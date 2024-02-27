#include <stdio.h>
#include "lodepng.h"
#include <stdlib.h>
#include <pthread.h>

// Global variables
int ***arr;  // 3D array to store RGB values of the image
unsigned char *image;  // Array to store image pixels

// Structure to hold parameters for each thread
struct pixels{
    int start_h, end_h, h, w, thread_id, kernel_size;
};

// Function to perform image blur (called by each thread)
void *blur(void *ptr)
{
    int i, j, l, m;
    struct pixels *arg = (struct pixels *)ptr;
    int start_h = arg->start_h, end_h = arg->end_h, kernel_size = arg->kernel_size;
    int thread_id = arg->thread_id, height = arg->h, width = arg->w;

    // Iterate over the assigned rows of pixels
    for (i = start_h; i <= end_h; i++)
    {
        for (j = 0; j < width; j++)
        {
            int avg_red = 0, avg_green = 0, avg_blue = 0, num_of_pixels = 0;

            // Iterate over the pixels in the kernel neighborhood
            for (l = -kernel_size; l <= kernel_size; l++)
            {
                for (m = -kernel_size; m <= kernel_size; m++)
                {
                    int x_pixel = i + l;
                    int y_pixel = j + m;

                    // Check if the pixel coordinates are within bounds
                    if (x_pixel >= 0 && y_pixel >= 0 && x_pixel < height && y_pixel < width)
                    {
                        avg_red += arr[x_pixel][y_pixel][0];
                        avg_green += arr[x_pixel][y_pixel][1];
                        avg_blue += arr[x_pixel][y_pixel][2];
                        num_of_pixels++;
                    }
                }
            }
            // Update the blurred pixel values in the output image
            image[4 * width * i + 4 * j + 0] = avg_red / num_of_pixels;
            image[4 * width * i + 4 * j + 1] = avg_green / num_of_pixels;
            image[4 * width * i + 4 * j + 2] = avg_blue / num_of_pixels;
        }
    }
    // Exit the thread
    pthread_exit(0);
}

int main()
{
    // Local variables
    unsigned int error, width, height;
    int i, j, k;
    int num_of_threads, kernel_size;
    char filename[20];

    // Get the input image filename from the user
    printf("Enter image you want to blur (with .png extension): ");
    scanf("%s", filename);

    // Decode the image and get its width and height
    error = lodepng_decode32_file(&image, &width, &height, filename);

    // Get the number of threads from the user
    printf("\nEnter number of threads to utilize to blur the image: ");
    scanf("%d", &num_of_threads);

    // Adjust the number of threads if it exceeds the image height
    if (num_of_threads > height)
    {
        num_of_threads = num_of_threads % height + 1;
        printf("\nThe number of threads is greater than height\nAutomatically choose required number of threads: %d threads", num_of_threads);
    }

    // Get the size of the blur kernel from the user
    printf("\n\nPlease enter the size (level of blur) of the Kernel (blur matrix) that you want to use\nEnter \"1\" for 3x3, \"2\" for 5x5, \"3\" for 7x7 matrix and so on: ");
    scanf("%d", &kernel_size);

    // Allocate memory for the 3D array to store RGB values
    arr = (int ***)malloc(height * sizeof(int **));
    for (i = 0; i < height; i++)
    {
        arr[i] = (int **)malloc(width * sizeof(int *));
        for (j = 0; j < width; j++)
        {
            arr[i][j] = (int *)malloc(3 * sizeof(int));
        }
    }

    // Check for decoding error
    if (error)
    {
        printf("Error in decoding image %d: %s\n", error, lodepng_error_text(error));
        return 1;
    }
    else
    {
        // Copy pixel values from the decoded image to the 3D array
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                arr[i][j][0] = image[4 * width * i + 4 * j + 0];
                arr[i][j][1] = image[4 * width * i + 4 * j + 1];
                arr[i][j][2] = image[4 * width * i + 4 * j + 2];
            }
        }
    }

    // Calculate the slice height for each thread
    int slice_height[num_of_threads];
    for (i = 0; i < num_of_threads; i++)
    {
        slice_height[i] = height / num_of_threads;
    }

    // Adjust the slice height for the remainder of the division
    int reminderHeight = height % num_of_threads;
    for (i = 0; i < reminderHeight; i++)
    {
        slice_height[i]++;
    }

    // Calculate the start and end heights for each thread
    int start_height[num_of_threads], end_height[num_of_threads];
    for (i = 0; i < num_of_threads; i++)
    {
        if (i == 0)
        {
            start_height[i] = 0;
        }
        else
        {
            start_height[i] = end_height[i - 1] + 1;
        }
        end_height[i] = start_height[i] + slice_height[i] - 1;
    }

    // Create an array of structures to hold thread parameters
    struct pixels divider[num_of_threads];
    // Create an array of thread IDs
    pthread_t threads[num_of_threads];
    int thid = 1;
    // Create threads and assign them their respective tasks
    for (i = 0; i < num_of_threads; i++)
    {
        divider[i].start_h = start_height[i];
        divider[i].end_h = end_height[i];
        divider[i].h = height;
        divider[i].w = width;
        divider[i].thread_id = thid;
        divider[i].kernel_size = kernel_size;
        thid++;
        pthread_create(&threads[i], NULL, blur, &divider[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < num_of_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Variables for output image encoding
    unsigned char *png;
    char image_name[20];
    size_t pngsize;
    // Prompt the user for the output image filename
    printf("\n\nImage has been blurred. Enter the name of the output blurred image (with .png extension): ");
    scanf("%s", image_name);

    // Encode the blurred image and save it to a file
    lodepng_encode32(&png, &pngsize, image, width, height);
    lodepng_save_file(png, pngsize, image_name);

    // Free allocated memory for the original image
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);
    
    // Free memory for the blurred image and encoding buffer
    free(image);
    free(png);

    // Return 0 to indicate successful execution
    return 0;
}

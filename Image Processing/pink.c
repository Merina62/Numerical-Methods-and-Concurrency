#include <stdio.h>
#include "lodepng.h"
#include <stdlib.h>

void main() {
    // Declare variables for image data
    unsigned char *Image;
    unsigned int width, height, red, green, blue, alpha;
    int i, j;

    // Declare variable for LodePNG error handling
    unsigned int error;

    // Decode the PNG file into the Image array
    error = lodepng_decode32_file(&Image, &width, &height, "xyz.png");
    if (error) {
        // Print an error message if decoding fails
        printf("Error opening a file %d: %s", error, lodepng_error_text(error));
    }

    // Print the dimensions of the image
    printf("Width: %d Height: %d\n", width, height);

    // Loop through each pixel in the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Extract color values (red, green, blue, alpha) for the current pixel
            red = Image[4 * width * i + 4 * j + 0];
            green = Image[4 * width * i + 4 * j + 1];
            blue = Image[4 * width * i + 4 * j + 2];
            alpha = Image[4 * width * i + 4 * j + 3];

            // Set the blue component to 255 (full intensity)
            blue = 255;
            Image[4 * width * i + 4 * j + 2] = blue;

            // Print the color values for the current pixel
            printf("[%d %d %d %d]", red, green, blue, alpha);
        }
        printf("\n");
    }

    // Declare variables for encoded PNG data
    unsigned char *png;
    size_t pngsize;

    // Encode the modified image back to PNG format
    error = lodepng_encode32(&png, &pngsize, Image, width, height);

    // Save the encoded PNG data to a new file if encoding is successful
    if (!error) {
        lodepng_save_file(png, pngsize, "purple.png");
    }

    // Free allocated memory for Image and png arrays
    free(Image);
    free(png);
}
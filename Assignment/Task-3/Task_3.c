#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>

// Global variables
int *prime_arr, primecount = 0;
FILE *fileptr;

// Mutex for thread synchronization
pthread_mutex_t mutex;

// Structure to hold the range of numbers to check for primality in each thread
struct calculate
{
    int start;
    int finish;
};

// Function to check if a number is prime
int check_prime(int n, int i)
{
    if (n <= 2)
        return (n == 2) ? 1 : 0;
    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
    return check_prime(n, i + 1);
}

// Thread function to find and write prime numbers within a given range
void *is_prime(void *ptr)
{
    struct calculate *arg = ptr;
    int st = arg->start, fi = arg->finish;
    int i;
    for (i = st; i <= fi; i++)
    {
        int num = *(prime_arr + i);
        if (check_prime(num, 2) == 1)
        {
            // Lock the mutex before updating shared resources
            pthread_mutex_lock(&mutex);
            primecount++;
            fprintf(fileptr, "%d\n", num);
            // Unlock the mutex after updating shared resources
            pthread_mutex_unlock(&mutex);
        }
    }
}

int main()
{
    // Local variables
    int i, n = 0, j = 0, nof = 3; // nof is the number of input files
    FILE *fptr;
    char filename[15], chr;
    int no_of_threads;

    // Count the total number of numbers to check across all input files
    for (i = 1; i <= nof; i++)
    {
        sprintf(filename, "PrimeData%d.txt", i);
        fptr = fopen(filename, "r");
        chr = getc(fptr);
        while (chr != EOF)
        {
            if (chr == '\n')
            {
                if (chr != ' ')
                    n++;
            }
            chr = getc(fptr);
        }
        fclose(fptr);
    }

    // Prompt the user for the number of threads to use
    printf("Find prime numbers from total (%d) numbers to check. Use multithreading to make the process faster", n);
    printf("\n\nEnter the number of threads to utilize: ");
    scanf("%d", &no_of_threads);

    // Create an array of structures to hold thread parameters
    struct calculate divider[no_of_threads];

    // Allocate memory for the array of numbers to check for primality
    prime_arr = (int *)malloc(n * sizeof(int));

    // Read numbers from input files into the prime_arr array
    for (i = 1; i <= nof; i++)
    {
        sprintf(filename, "PrimeData%d.txt", i);
        fptr = fopen(filename, "r");

        while (!feof(fptr))
        {
            fscanf(fptr, "%d\n", (prime_arr + j));
            j++;
        }
        fclose(fptr);
    }

    // Calculate the number of numbers each thread will check
    int slice_list[no_of_threads];
    for (i = 0; i < no_of_threads; i++)
        slice_list[i] = n / no_of_threads;

    // Adjust the slice sizes for any remainder
    int reminder = n % no_of_threads;
    for (i = 0; i < reminder; i++)
        slice_list[i]++;

    // Calculate the start and end indices for each thread
    int start_list[no_of_threads], end_list[no_of_threads];
    for (i = 0; i < no_of_threads; i++)
    {
        if (i == 0)
            start_list[i] = 0;
        else
            start_list[i] = end_list[i - 1] + 1;
        end_list[i] = start_list[i] + slice_list[i] - 1;
    }

    // Open the output file for writing prime numbers
    fileptr = fopen("Prime.txt", "w");

    // Initialize the mutex for thread synchronization
    pthread_mutex_init(&mutex, NULL);

    // Create an array of thread IDs
    pthread_t threads[no_of_threads];

    // Create threads and assign them their respective tasks
    for (i = 0; i < no_of_threads; i++)
    {
        divider[i].start = start_list[i];
        divider[i].finish = end_list[i];
        pthread_create(&threads[i], NULL, is_prime, &divider[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < no_of_threads; i++)
        pthread_join(threads[i], NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Display the total count of prime numbers
    printf("\nTotal Prime Count: %d\n", primecount);

    // Write the total count to the output file
    fprintf(fileptr, "\n\nThere are total of %d prime numbers.", primecount);

    // Free allocated memory
    free(prime_arr);

    // Display completion message
    printf("\nProcess complete!!\n\n\"Prime.txt\" file has been created.\n");

    // Close the output file
    fclose(fileptr);

    // Return 0 to indicate successful execution
    return 0;
}

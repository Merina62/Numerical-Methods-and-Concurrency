// Convert program no. 2 to accept an integer to specify the
//number of threads and then create that number of threads
//dynamically. All the threads will equally contribute to display
//the numbers from 1-1000.

#include <stdio.h>
#include <pthread.h>

int MAX_THREADS = 10;
int MAX_NUMBER = 1000;

// Global variable to be shared among threads
int n;

// Function to be executed by each thread
void* thread_function(void* arg) {
    int thread_number = *(int*)arg;

    for (int i = thread_number; i <= MAX_NUMBER; i += n) {
        printf("%d\n", i);
    }

    pthread_exit(NULL);
}

int main() {
    printf("Enter the number of threads (up to %d): ", MAX_THREADS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_THREADS) {
        printf("Invalid number of threads. Exiting.\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int thread_numbers[MAX_THREADS];

    // Creating the threads
    for (int i = 0; i < n; ++i) {
        thread_numbers[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_function, &thread_numbers[i]);
    }

    // Joining threads
    for (int i = 0; i < n; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}






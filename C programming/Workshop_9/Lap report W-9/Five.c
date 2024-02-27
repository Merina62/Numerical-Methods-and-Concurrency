// Create a multithreaded program to display all the odd numbers from 1-1000. Your
// program should ask the user to input the number of threads. Based on the number of
//threads you should divide the workload among the threads
#include <stdio.h>
#include <pthread.h>

int num_threads;

void* print_odd_numbers(void* thread_id) {
    int tid = (intptr_t)thread_id; 
    int start = tid * (1000 / num_threads) + 1;
    int end = (tid + 1) * (1000 / num_threads);

    if (tid == num_threads - 1) {
        end = 1000;
    }

    for (int i = start; i <= end; i += 2) {
        printf("Thread %d: %d\n", tid + 1, i);
    }

    pthread_exit(NULL);
}

int main() {
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[num_threads];
    int i;

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, print_odd_numbers, (void*)(intptr_t)i);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

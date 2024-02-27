// Convert program no.3 to accept an integer to specify the number of threads and then
// create that number of threads dynamically. All the threads will equally contribute to
// display the numbers from 1-1000.

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* displayNumbers(void* arg) { 
    int* thread_id = (int*)arg;
    int i;
    for (i = *thread_id; i <= 1000; i += 5) {
        printf("Thread %d: %d\n", *thread_id, i);
    }
    return NULL;
}
int main() {
    int num_threads;
    int i;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);
    
    pthread_t* threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
    int* thread_ids = (int*)malloc(num_threads * sizeof(int));
    for (i = 0; i < num_threads; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, displayNumbers, &thread_ids[i]);
    }
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    free(threads);
    free(thread_ids);
    return 0;
}
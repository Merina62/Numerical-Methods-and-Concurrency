#include <stdio.h>
#include <pthread.h>
#include <math.h>

//Declare and initialize gloable variable
int NUM_THREADS = 16;
//Decalre an array with size 14
double sum[14];
int iterations_per_thread;

//Decalre a void function
void *leibniz_series(void *threadid);

int main()
{
	//Declare variables
    int num_iterations;
    int num_threads;
    pthread_t threads[NUM_THREADS];
    int error;
    int i;
    double pi;

	 // User input for the number of iterations and threads.
    printf("Enter the number of iterations: ");
    scanf("%d", &num_iterations);
    
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

	// Calculate the number of iterations per thread.
    iterations_per_thread = num_iterations / num_threads;

	// Thread creation loop
    for (i = 0; i < num_threads; i++)
    {
        error = pthread_create(&threads[i], NULL, leibniz_series, (void *)(intptr_t)i);
        if (error)
        {
            printf("Error creating thread\n");
            return 1;
        }
    }
	
	// Thread joining loop
    for (i = 0; i < num_threads; i++){
    	pthread_join(threads[i], NULL);
	}
        

	// Summing up the partial results to calculate Pi
    pi = 0;

    for (i = 0; i < num_threads; i++){
    	pi += sum[i];
	}
        
    pi *= 4;

    printf("The calculated value of Pi is: %f\n", pi);
    pthread_exit(NULL);

    return 0;
}

void *leibniz_series(void *threadid)
{
    int start = (intptr_t)threadid * iterations_per_thread;
    int end = (intptr_t)threadid * iterations_per_thread + iterations_per_thread;

    int i;
    double result = 0;

	// Leibniz series calculation within the assigned range
    for (i = start; i < end; i++){
        result += pow(-1, i) / (2 * i + 1);
	}
	// Storing the result in the corresponding position in the 'sum' array.
    sum[(intptr_t)threadid] = result;
    pthread_exit(NULL);
}
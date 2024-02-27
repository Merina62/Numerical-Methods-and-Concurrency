// Write a program that reads ‘n’ from the
//user and allocates memory to hold n
//integer numbers. Pass these numbers
//to a function that returns the sum.


#include <stdio.h>
#include <stdlib.h>
int i;
// Function to calculate the sum of array elements
int calculateSum(int *arr, int size) {
    int sum = 0;
    for (i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the number of integers (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;  // Return an error code
    }

    // Dynamically allocate memory for the array
    int *dynamicArray = (int *)malloc(n * sizeof(int));

    if (dynamicArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Return an error code
    }

    // Get values for the array from the user
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &dynamicArray[i]);
    }

    // Calculate the sum of array elements using the function
    int sum = calculateSum(dynamicArray, n);

    // Display the result
    printf("Sum of array elements: %d\n", sum);

    // Free dynamically allocated memory
    free(dynamicArray);

    return 0;
}

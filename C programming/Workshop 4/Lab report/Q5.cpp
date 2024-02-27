// Write a program that allocates memory space as required by the user
// for three arrays. User enters the numbers for two arrays and the
// program sums the corresponding array elements and stores them in
// the third array.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int size, i;
    // Get the size of the arrays from the user
    printf("Enter the size of the arrays: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;  // Return an error code
    }
    // Dynamically allocate memory for three arrays
    int *array1 = (int *)malloc(size * sizeof(int));
    int *array2 = (int *)malloc(size * sizeof(int));
    int *sumArray = (int *)malloc(size * sizeof(int));

    if (array1 == NULL || array2 == NULL || sumArray == NULL) {
        printf("Memory allocation failed.\n");
        // Free allocated memory before returning an error code
        free(array1);
        free(array2);
        free(sumArray);
        return 1;  // Return an error code
    }
    // Get values for the first array from the user
    printf("Enter values for first array:\n");
    for (i = 0; i < size; ++i) {
        scanf("%d", &array1[i]);
    }
    // Get values for the second array from the user
    printf("Enter values for second array:\n");
    for (i = 0; i < size; ++i) {
        scanf("%d", &array2[i]);
    }
    // Calculate the sum of corresponding elements and store in the third array
    for (i = 0; i < size; ++i) {
        sumArray[i] = array1[i] + array2[i];
    }
    // Display the result
    printf("Sum of corresponding elements:\n");
    for (i = 0; i < size; ++i) {
        printf("%d ", sumArray[i]);
    }
    printf("\n");
    // Free dynamically allocated memory
    free(array1);
    free(array2);
    free(sumArray);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
int i;
int findMaximum(int *array, int size) {
    if (size <= 0) {
        printf("Invalid array size.\n");
        return -1;  // Return a sentinel value indicating an error
    }
    int max = array[0];  // Assume the first element as the initial maximum
    for (i = 1; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];  // Update the maximum if a larger value is found
        }
    }
    return max;
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;  
    }
    int *ptr = (int *)malloc(size * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; 
    }
 
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; ++i) {
        scanf("%d", &ptr[i]);
    }

    int max = findMaximum(ptr, size);
    if (max != -1) {
        printf("The maximum value in the array is: %d\n", max);
    } else {
        printf("Error finding maximum value.\n");
    }
    free(ptr);
    return 0;
}

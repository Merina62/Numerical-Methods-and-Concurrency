#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, new_size;

    // Input the size of the original array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the original array
    int *arr = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the elements of the original array
    printf("\nElements of the original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input the number of elements to be added
    printf("\nEnter the number of elements to add: ");
    scanf("%d", &new_size);

    // Resize the array using realloc to add more elements
    arr = (int*)realloc(arr, (size + new_size) * sizeof(int));

    for (int i = size; i < size + new_size; i++) {
        printf("Enter the element for index %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    // Print the final array without indices
    printf("\nThe final array: ");
    for (int i = 0; i < size + new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}

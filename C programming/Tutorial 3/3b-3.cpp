// Write a program to replace each element in an array with the integer value 5. You must take input from users in the main function and save it in an array. You must also take the
// size of an array from the user.You must create a function that takes two parameters: an array and length of the array. Your function should not return anything and
//it should not print anything. You must print before and after replacing an element in an array in the main function. 
#include <stdio.h>
// void function to replace all element with 5
void replace(int arr[], int length) { 
    for (int i = 0; i < length; i++) { //for loop is used to go through each element
        arr[i] = 5; // replace that element with 5
    }
}
int main() {
    // Initializing size and taking input of the size
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Prompt the user to enter each element of array
    int array[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    // Prints the array before replacement
    printf("Array before replacement: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    // Function call to replace elements with 5
    replace(array, size);

    // Prints the array after replacement
    printf("Array after replacement: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0; 
}

// Write a c program to read integers from the user and append the sum to the end in the file
// name sum.txt.

#include <stdio.h>

int main() {
    FILE *sumFile = fopen("sum.txt", "a");

    if (sumFile == NULL) {
        printf("Error opening sum.txt for appending.\n");
        return 1; // Exit with an error code
    }

    int number, sum = 0;

    do {
        // Read an integer from the user
        printf("Enter an integer (enter 0 to stop): ");
        scanf("%d", &number);

        // Add the number to the sum
        sum += number;

    } while (number != 0);

    // Append the sum to sum.txt
    fprintf(sumFile, "Sum: %d\n", sum);

    // Close the file
    fclose(sumFile);

    printf("Sum appended to sum.txt successfully.\n");

    return 0;
}
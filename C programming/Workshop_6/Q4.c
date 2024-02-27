// Write a program in C to read integers from the user until the user says "no". After
// reading the data write all the odd numbers to a file named odd.txt and all the
// even numbers to file even.txt.

#include <stdio.h>

int main() {
    int number;
    char response[3]; // Assuming "no" or "yes" as possible responses

    // Open files for writing
    FILE *evenFile = fopen("even.txt", "w");
    FILE *oddFile = fopen("odd.txt", "w");

    // Check if files were opened successfully
    if (evenFile == NULL || oddFile == NULL) {
        printf("Error opening files for writing.\n");
        return 1; // Exit with an error code
    }

    do {
        // Read an integer from the user
        printf("Enter an integer: ");
        scanf("%d", &number);

        // Check if the number is even or odd
        if (number % 2 == 0) {
            // Write even number to even.txt
            fprintf(evenFile, "%d\n", number);
        } else {
            // Write odd number to odd.txt
            fprintf(oddFile, "%d\n", number);
        }

        // Ask the user if they want to enter another number
        printf("Do you want to enter another number? (yes/no): ");
        scanf("%s", response);

    } while (strcmp(response, "no") != 0);

    // Close files
    fclose(evenFile);
    fclose(oddFile);

    printf("Numbers written to even.txt and odd.txt successfully.\n");

    return 0; // Exit program successfully
}

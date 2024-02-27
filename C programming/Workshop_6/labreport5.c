// Write a program to copy content from odd.txt and event.txt file to a new file numbers.txt file.

#include <stdio.h>

int main() {
    // Open the source files (odd.txt and even.txt) for reading
    FILE *oddFile = fopen("odd.txt", "r");
    FILE *evenFile = fopen("even.txt", "r");

    // Open the destination file (numbers.txt) for writing
    FILE *destinationFile = fopen("numbers.txt", "w");

    // Check if files were opened successfully
    if (oddFile == NULL || evenFile == NULL || destinationFile == NULL) {
        printf("Error opening files.\n");
        
        // Close the files that were successfully opened
        if (oddFile != NULL) fclose(oddFile);
        if (evenFile != NULL) fclose(evenFile);
        if (destinationFile != NULL) fclose(destinationFile);
        
        return 1; // Exit with an error code
    }

    // Copy content from odd.txt to numbers.txt
    int ch;
    while ((ch = fgetc(oddFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    // Copy content from even.txt to numbers.txt
    while ((ch = fgetc(evenFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    // Close all files
    fclose(oddFile);
    fclose(evenFile);
    fclose(destinationFile);

    printf("Content copied successfully from odd.txt and even.txt to numbers.txt.\n");

    return 0; // Exit program successfully
}

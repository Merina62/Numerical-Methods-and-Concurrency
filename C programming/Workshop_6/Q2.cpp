#include <stdio.h>

int main() {
    char c;
    FILE *file1, *file2;

    // Open the source file
    file1 = fopen("employee.txt", "r");
    if (file1 == NULL) {
        perror("Error opening employee.txt");
        return 1;
    }

    // Open the destination file
    file2 = fopen("newemployee.txt", "w");
    if (file2 == NULL) {
        perror("Error opening newemployee.txt");
        fclose(file1);
        return 1;
    }

    // Copy content from source to destination
    while ((c = fgetc(file1)) != EOF) {
        fputc(c, file2);
    }

    // Check for errors during copying
    if (ferror(file1) || ferror(file2)) {
        perror("Error copying content");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    // Close the files
    fclose(file1);
    fclose(file2);

    printf("File copied successfully\n");

    return 0;
}

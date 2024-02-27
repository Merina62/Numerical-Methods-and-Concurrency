//Copy the contents of Student.txt to newstudent.txt
#include <stdio.h>

int main() {
    char c;
    FILE *file1;
    FILE *file2;

    file1 = fopen("Student.txt", "r");

    if (file1 == NULL) {
        printf("Error opening Student.txt\n");
        return 1;  // Exit with an error code
    }

    file2 = fopen("newStudent.txt", "w");

    if (file2 == NULL) {
        printf("Error opening newStudent.txt\n");
        fclose(file1);  // Close the first file before returning
        return 1;       // Exit with an error code
    }

    do {
        c = fgetc(file1);
        if (c != EOF) {
            fputc(c, file2);
        }
    } while (c != EOF);

    printf("File copied successfully\n");

    fclose(file1);
    fclose(file2);

    return 0;  // Exit successfully
}
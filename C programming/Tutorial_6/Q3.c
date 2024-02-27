//add datas of two students in newstudent.txt
//Add datas of one students in newStudent.txt
#include <stdio.h>

int main() {
    char name1[50];
    int roll1;
    char grade1;

    FILE *file = fopen("newStudent.txt", "a");

    if (file != NULL) {
        // Input details for Student 4
        printf("Enter details for Student 4:\n");
        printf("Enter Name: ");
        scanf("%s", name1);
        printf("Enter Roll: ");
        scanf("%d", &roll1);
        
        // Consume the newline character left in the buffer after the previous scanf
        getchar();
        
        printf("Enter Grade: ");
        scanf(" %c", &grade1);  

        // Write details to the file
        fprintf(file, "\nDetails of Student 4\n");
        fprintf(file, "Name: %s\n", name1);
        fprintf(file, "Roll No: %d\n", roll1);
        fprintf(file, "Grade: %c\n", grade1);

        // Close the file
        fclose(file);

        printf("Details added successfully to newStudent.txt\n");
    } else {
        printf("Error opening newStudent.txt\n");
    }

    return 0;
}
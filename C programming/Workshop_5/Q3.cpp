#include <stdio.h>

// Define the structure
struct student {
    char name[50];
    int roll_number;
    float marks;
};

// Function to read information of students
void readInformation(struct student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll_number);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("\n");
    }
}

// Function to display information of students
void displayInformation(struct student *students, int numStudents) {
    printf("\nStudent Information:\n");  // Print a header for the student information
    printf("-------------------------------------------------\n");  // Print a separator line
    printf("| %-20s | %-15s | %-5s |\n", "Name", "Roll Number", "Marks");
    // Print a formatted table header with column names
    printf("-------------------------------------------------\n");  // Print a separator line

    for (int i = 0; i < numStudents; i++) {
        printf("| %-20s | %-15d | %-5.2f |\n", students[i].name, students[i].roll_number, students[i].marks);
        // Print formatted rows with student information
        // %-20s: Left-justified string with a width of 20 characters
        // %-15d: Left-justified integer with a width of 15 characters
        // %-5.2f: Left-justified floating-point number with a width of 5, including 2 decimal places
    }

    printf("-------------------------------------------------\n");  // Print a separator line
}


int main() {
    // Declare an array of 10 students
    struct student students[10];

    // Read information of students
    readInformation(students, 10);

    // Display information of students
    displayInformation(students, 10);

    return 0;
}
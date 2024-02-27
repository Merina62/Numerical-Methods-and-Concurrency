// WAP to add new employee details in newemployee.txt file.
//3. WAP to add new employee details in newemployee.txt file.
#include <stdio.h>

struct Employee {
    char empName[50];
    int age;
    int salary;
};

int main() {
	int i;
    struct Employee employee;  // Define a single employee structure
    char choice;

    FILE *file = fopen("newemployee.txt", "a");

    if (file != NULL) {
        for (i = 5; i < 7; ++i) {
            // Input details for the employee
            printf("Details for Employee %d:\n", i + 1);
            printf("Name: ");
            scanf("%s", employee.empName);
            printf("Age: ");
            scanf("%d", &employee.age);
            printf("Salary: ");
            scanf("%d", &employee.salary);

            // Write details to the file
            fprintf(file, "Employee %d\n", i + 1);
            fprintf(file, "Name: %s\n", employee.empName);
            fprintf(file, "Age: %d\n", employee.age);
            fprintf(file, "Salary: %d\n", employee.salary);
            fprintf(file, "\n");


            printf("Details for Employee %d added successfully to newemployee.txt\n", i + 1);
        }

        // Close the file 
        fclose(file);
    } else {
        printf("Error opening newemployee.txt\n");
    }

    return 0;
}
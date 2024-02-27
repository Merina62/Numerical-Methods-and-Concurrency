#include <stdio.h>
#include <stdlib.h>

// Define the structure for employee information
struct Employee {
    char name[50];
    float salary;
    int hoursWorked;
};

// Function to find and print the highest salary
void findHighestSalary(struct Employee* employees, int n) {
    float highestSalary = employees[0].salary;
    int index = 0;

    for (int i = 1; i < n; ++i) {
        if (employees[i].salary > highestSalary) {
            highestSalary = employees[i].salary;
            index = i;
        }
    }

    printf("Employee with the highest salary:\n");
    printf("Name: %s, Salary: $%.2f\n", employees[index].name, employees[index].salary);
}

int main() {
    int n;

    // Get the number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Dynamically allocate an array of structures
    struct Employee* employees = (struct Employee*)malloc(n * sizeof(struct Employee));

    // Input information for each employee
    for (int i = 0; i < n; ++i) {
        struct Employee* currentEmployee = &employees[i];

        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", currentEmployee->name);

        printf("Enter the salary of employee %d: $", i + 1);
        scanf("%f", &currentEmployee->salary);

        printf("Enter the hours of work per day for employee %d: ", i + 1);
        scanf("%d", &currentEmployee->hoursWorked);
    }

    // Call the function to find and print the highest salary
    findHighestSalary(employees, n);

    // Free the dynamically allocated memory
    free(employees);

    return 0;
}

#include <stdio.h>
#include <string.h>

// Define the structure for employee information
struct Employee {
    char name[50];
    float salary;
    int hoursWorked;
};

// Function to calculate the salary increase based on hours worked
float calculateSalaryIncrease(int hoursWorked) {
    if (hoursWorked >= 12) {
        return 150.0;
    } else if (hoursWorked >= 10) {
        return 100.0;
    } else if (hoursWorked >= 8) {
        return 50.0;
    } else {
        return 0.0;
    }
}

int main() {
    // Create an array to store information for 5 employees
    struct Employee employees[5];

    // Input information for each employee
    for (int i = 0; i < 5; ++i) {
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", employees[i].name);

        printf("Enter the salary of employee %d: $", i + 1);
        scanf("%f", &employees[i].salary);

        printf("Enter the hours of work per day for employee %d: ", i + 1);
        scanf("%d", &employees[i].hoursWorked);
    }

    // Update salary based on hours worked
    for (int i = 0; i < 5; ++i) {
        float increase = calculateSalaryIncrease(employees[i].hoursWorked);
        employees[i].salary += increase;
    }

    // Print the final information for each employee
    printf("\nEmployee Information:\n");
    for (int i = 0; i < 5; ++i) {
        printf("Name: %s, Final Salary: $%.2f\n", employees[i].name, employees[i].salary);
    }

    return 0;
}

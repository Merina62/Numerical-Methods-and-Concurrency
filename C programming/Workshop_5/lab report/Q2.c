i#include<stdio.h>

struct Employee {
    char name[20];
    char post[50];
    int salary;
};

// Function to filter employees with salary greater than 10000
struct Employee filterEmployees(struct Employee emp[], int n) {
    struct Employee filteredEmp[10];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (emp[i].salary > 10000) {
            filteredEmp[count] = emp[i];
            count++;
        }
    }

    // Update the number of elements in the filtered array
    filteredEmp[0].salary = count;

    return filteredEmp[0];
}

int main() {
    struct Employee emp[5];

    // Input employee details
    for (int i = 0; i < 5; i++) {
        printf("Enter the name of employee(%d): ", i + 1);
        scanf("%s", emp[i].name);
        printf("Enter the post of employee(%d): ", i + 1);
        scanf("%s", emp[i].post);
        printf("Enter the salary of employee(%d): ", i + 1);
        scanf("%d", &emp[i].salary);
    }

    // Get filtered employees
    struct Employee filteredEmp = filterEmployees(emp, 5);

    // Display filtered employees
    printf("\nEmployees whose salary is greater than 10000:\n");

    // Use filteredEmp.salary to get the count, and iterate accordingly
    for (int i = 0; i < filteredEmp.salary; i++) {
        printf("Employee(%d) name: %s\n", i + 1, filteredEmp.name);
        printf("Employee(%d) post: %s\n", i + 1, filteredEmp.post);
        printf("Employee(%d) salary: %d\n", i + 1, filteredEmp.salary);
        printf("\n");
    }

    return 0;
}

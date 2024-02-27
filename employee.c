
//4. WAP to input name, post and salary of ten employees from main() function and pass to structure type user defined function(argument of this
// function should also be a structure type). This function returns a structure variable which keeps the record of only those employees whose
// salary is greater than 10,000. This modified record is also displayed from the main() function
#include <stdio.h>
// Define the structure for employee information
struct Employee {
    char name[50];
    char post[50];
    float salary;
};
// Function to filter employees with salary greater than 10,000
void filterEmployees(struct Employee emp[], int n) {
    printf("\nEmployees with salary greater than 10,000:\n");
    printf("%-20s %-20s %-20s\n", "Name", "Post", "Salary");
    printf("---------------------------------------------------\n");
	int i;
    for (i = 0; i < n; i++) {
        if (emp[i].salary > 10000) {
            printf("%-20s %-20s %-20.2f\n", emp[i].name, emp[i].post, emp[i].salary);
        }
    }
}
int main() {
    // Declare an array of Employee structures
    struct Employee employees[10];
	int i;
    // Input employee information from the user
    printf("Enter details for 10 employees:\n");
    for (i = 0; i < 10; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Post: ");
        scanf("%s", employees[i].post);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    // Call the function to filter employees with salary greater than 10,000
    filterEmployees(employees, 10);

    return 0;
}

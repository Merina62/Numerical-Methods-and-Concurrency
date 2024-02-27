
#include <stdio.h>
// Define the structure for employee information
struct Employee {
    char name[50];
    char post[50];
    float salary;
};
// Function to filter employees with salary greater than 10,000
void filterEmployees(struct Employee emp[], int n) {
    printf("\nEmployees with a salary greater than 10,000:\n");
	
	for (int i = 0; i < n; i++) {
	    if (emp[i].salary > 10000) {
	        printf("Employee with salary more than 10,000:\n");
	        printf("Name: %s\n", emp[i].name);
	        printf("Post: %s\n", emp[i].post);
	        printf("Salary: %.2f\n\n", emp[i].salary);
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
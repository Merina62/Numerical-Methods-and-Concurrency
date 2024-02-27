-// Create a structure named employee having members: empName, age and
//salary. Use this structure to read the name, age and salary of the 5 employees
//and write entered information to a file employee.txt in D:\ drive.

#include<stdio.h>
struct Employee{
	char empName[20];
	int age;
	int salary;
};


int main(){
	
	struct Employee employees[5];
	for (int i = 0; i < 5; ++i) {
        printf("Enter details for Employee %d:\n", i + 1);
        
        // Read employee name
        printf("Name: ");
        scanf("%s", employees[i].empName);

        // Read employee age
        printf("Age: ");
        scanf("%d", &employees[i].age);

        // Read employee salary
        printf("Salary: ");
        scanf("%d", &employees[i].salary);

        printf("\n");
    }
    // Open a file for writing on the D:\ drive
FILE *file = fopen("D:\\Numerical and Concurrency\\C programming\\Workshop_6\\employee.txt", "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1; // Exit with an error code
    }

    // Write employee information to the file
    for (int i = 0; i < 5; ++i) {
        fprintf(file, "Employee %d\n", i + 1);
        fprintf(file, "Name: %s\n", employees[i].empName);
        fprintf(file, "Age: %d\n", employees[i].age);
        fprintf(file, "Salary: %d\n\n", employees[i].salary);
    }

    // Close the file
    fclose(file);

    printf("Employee information written to D:\\employee.txt successfully.\n");

    return 0; // Exit program successfully
}






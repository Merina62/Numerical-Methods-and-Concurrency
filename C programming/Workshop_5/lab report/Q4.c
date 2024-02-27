// Create a structure name Student and inside that struct include two data members'
// roll no and marks, inside that struct student definition create another struct named
// student_info where you should include three data members' name, age, and date
// of birth and print it out for 3 students.

#include<stdio.h>
struct Student{
	int rollno;
	float marks;
};
struct student_info{
	char name[20];
	int age;
	int dob;
	struct Student stud;
}info[3];


int main() {
    for (int i = 0; i < 3; i++) {
        printf("Enter name of student[%d]: ", i + 1);
        scanf("%s", info[i].name);

        printf("Enter age of student[%d]: ", i + 1);
        scanf("%d", &info[i].age);

        printf("Enter rollno of student[%d]: ", i + 1);
        scanf("%d", &info[i].stud.rollno);

        printf("Enter marks of student[%d]: ", i + 1);
        scanf("%f", &info[i].stud.marks);

        printf("Enter date of birth (Year) of student[%d]: ", i + 1);
        scanf("%d", &info[i].dob);
        
        printf("\n");
    }
	
	printf("Information of 3 students:\n ");
	for (int i = 0; i < 3; i++) {
        printf("\nName of student[%d]: %s\n", i + 1, info[i].name);
        printf("\nAge of student[%d]: %d\n", i + 1, info[i].age);
        printf("\nRoll no of student[%d]: %d\n", i + 1, info[i].stud.rollno);
        printf("\nMarks of student[%d]: %.2f\n", i + 1, info[i].stud.marks);
        printf("\nDate of Birth of student[%d]: %d\n", i + 1, info[i].dob);
    }
	
}






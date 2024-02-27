// Create a structure named student that has a name, roll number and marks as
// members. Assume appropriate types and size of members. Use this structure to
// read and display records of 10 students. Create two functions: One is to read
// information of students and other to display the information.

#include<stdio.h>
struct student{
	char name[20];
	int rollno;
	float marks;
};

struct student stud[10];
int record(){
	for(int i=0; i<10;i++){
	printf("Enter name of student(%d) : ",i+1);
	scanf("%s", stud[i].name);
	printf("Enter rollno of student(%d): ",i+1);
	scanf("%d", &stud[i].rollno);
	printf("Enter marks of student(%d): ",i+1);
	scanf("%f", &stud[i].marks);	
	}
	return 0;
}

int main(){
	record();
	printf("\nStudent Information: ");
	for(int i=0;i<10;i++){
		printf("\n Name of student(%d): %s ",i+1, stud[i].name);
		printf("\n Roll no of student(%d): %d",i+1,stud[i].rollno);
		printf("\n Marks of student(%d): %f",i+1,stud[i].marks);
	}
	return 0;
}
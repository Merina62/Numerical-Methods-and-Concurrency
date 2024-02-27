#include<stdio.h>
struct Student{
	char name[20];
	int roll;
	float grade;
};
struct Student stud[3];

int main(){
	for(int i=0;i<3;i++){
		printf("Enter name of student[%d]: ",i+1);
		scanf("%s",stud[i].name);
		printf("Enter roll no of student[%d]: ",i+1);
		scanf("%s",&stud[i].roll);
		printf("Enter grade of student[%d]: ",i+1);
		scanf("%f",&stud[i].grade);
		printf("\n");
	}
	
	printf("\nDetails of students: ");
	for(int i=0;i<3;i++){
		printf("\nName of student[%d]: %s ",i+1,stud[i].name);
		printf("\nRoll no of student[%d]: %d",i+1,stud[i].roll);
		printf("\nGrade of student[%d]: %f",i+1,stud[i].grade);
	}
	
	FILE *file;
	file= fopen("Student.txt","w");
	for(int i=0;i<3;i++){
		fprintf(file,"\nName of student[%d]: ",i+1,stud[i].name);
		fprintf(file,"\nRoll no of student[%d]: ",i+1,stud[i].roll);
		fprintf(file,"\nGrade of student[%d]: ",i+1,stud[i].grade);
	}
	fclose(file);
}





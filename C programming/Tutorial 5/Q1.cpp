#include<stdio.h>
int main(){	
	struct Student{
		char name[20];
		int age;
		float grade;
	};

	struct Student stu[5];
	int i;
	for(i=0;i<5;i++){
		printf("Enter name: ");
		scanf("%s", stu[i].name);
		
		printf("Enter your age: ");
		scanf("%d", &stu[i].age);
		
		printf("Enter your grade: ");
		scanf("%f",&stu[i].grade);
	}
	
	for(i=0;i<5;i++){
		if(stu[i].grade>80){
			printf("\n %s \n %d \n %.2f",stu[i].name ,stu[i].age , stu[i].grade);
		}
	}
	return 0;
}
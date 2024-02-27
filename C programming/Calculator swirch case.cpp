// Write a program to create simple calculator using switch case. (The operators +, -, *, /and % must be asked to user as a character.)
# include <stdio.h>
// create a function main
int main(){
	// initalize variables
	int a,b;
	char choice;
	// Get the input from the user and store then in respective variables
	printf("Enter a number: \n");
	scanf("%d",&a);
	
	printf("Enter another number: \n");
	scanf("%d",&b);
	// Ask the user to perform the operation
	printf("Which operation you want to use(+,-,*,/,%%)? \n");
	scanf(" %c",&choice);
	
	switch(choice){
		case '+':
			printf("%d + %d = %d\n ", a,b,a+b);
			break;
		case '-':
			printf("%d - %d = %d\n", a,b,a-b);
			break;
		case '*':
			printf("%d * %d = %d\n", a,b,a*b);
			break;
		case '/':
			printf("%d / %d = %d\n", a,b,a/b);
			break;
		case '%':
			printf("%d %% %d = %d\n", a,b,a%b);
			break;	
		default:
			printf("Invalid Input Operator \n");
	}
	return 0;
}

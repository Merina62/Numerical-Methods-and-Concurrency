#include <stdio.h>
//function declaration
int addNumbers(int a, int b);
int main(){
	int num1= 5;
	int num2= 10;
	int sum;
	
	sum=addNumbers(num1,num2);
	printf("Sum : %d \n", sum);
	return 0;
}
int addNumbers(int a, int b){
	int result= a+b;
	return result;
}

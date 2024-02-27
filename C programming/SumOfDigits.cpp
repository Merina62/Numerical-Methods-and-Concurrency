// Write a program to print the sum of digits of the number provided by user
# include <stdio.h>
//  Create a function main
int main(){
	int num, sum; //initialize num and sum
	// Get the number from user and store in num
	printf("Enter a number to find the sum of its digits:");
	scanf("%d", &num);
	sum=0; 
	//run until num is not equal to 0
	while(num!=0){
		// add the sum and reminder
		sum=sum+ num%10;
		// assisgn num value by the quotient of num/10
		num= num/10;
	}
	// print the result
	printf("Sum: %d",sum);
	return 0;
}


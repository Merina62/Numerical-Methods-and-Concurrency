#include <stdio.h>
int isEven(int num);
	
int main(){
	int number;
	printf("Enter a number: ");
	scanf("%d",&number);
		
	if(isEven(number)){
		printf("%d is an even number.\n",number);
	} else {
		printf("%d is an odd number.\n",number);
	}
	return 0;
}
int isEven(int num){
	if(num%2==0){
		return 1;
	} else {
		return 0;
	}
}

#include <stdio.h>
int main(){
	float f;
	printf("Enter Your Final score in percentage: ");
	scanf("%f", &f);
	if(f>=80){
		printf("You scored distinction.");
	}else if(f>=60){
		printf("You scored first division.");
	} else if(f>=50){
		printf("You scored second division.");
	} else if(f>=40){
		printf("You scored third division.");
	} else if(f<40){
		printf("You are fail.");
	}
	return 0;
}

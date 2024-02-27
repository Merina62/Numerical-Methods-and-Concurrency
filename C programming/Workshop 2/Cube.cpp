#include <stdio.h>
int findCubeNumber(int a){
	int cube= a*a*a;
	return cube;
}

int main(){
	int n;
	printf("Enter a number to find the cube of it: \n");
	scanf("%d",&n);
	int result=	findCubeNumber(n);
	printf("The cube number of %d is %d", n,result);
	return 0;
}

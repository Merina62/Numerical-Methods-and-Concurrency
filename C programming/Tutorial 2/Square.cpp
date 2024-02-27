#include <stdio.h>
int square(int a);
int main(){
	int n,s;
	printf("Enter a number: ");
	scanf("%d", &n);
	s= square(n);
	printf("Square: %d",s);
	return 0;
}
int square(int a){
	int result= a*a;
	return result;
}

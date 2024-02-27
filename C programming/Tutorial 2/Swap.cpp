# include <stdio.h>
int swap(int *a, int *b);
int main(){
	int n1,n2;
	printf("Enter a number: ");
	scanf("%d", &n1);
	
	printf("Enter another number: ");
	scanf("%d", &n2);
	
	printf("Before swapping: \n");
	printf("First number: %d \n",n1);
	printf("Second number: %d \n",n2);
	
	swap(&n1,&n2);
	printf("After swapping: \n");
	printf("First number: %d \n",n1);
	printf("Second number: %d \n",n2);
	return 0;
	
}
int swap(int *a, int *b){
	int m= *a;
	*a= *b;
	*b=m;
	return 0;
}

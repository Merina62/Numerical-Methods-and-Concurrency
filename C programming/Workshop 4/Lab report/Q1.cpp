// Write a program in C to compute the sum of all elements in an array using pointer.
#include<stdio.h>
int main(){
	int num,i;
	printf("Enter the size of an array: ");
	scanf("%d",&num);
	int arr[num];
	for(i=0;i<num;i++){
		printf("Enter a number %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	int *ptr= arr;
	int sum=0;
	for(i=0;i<num;i++){
		sum=sum+*ptr;
		ptr++;	
	}
	printf("Total sum of array elements: %d",sum);
	return 0;
}
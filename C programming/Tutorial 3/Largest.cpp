#include<stdio.h>
int main(){
	int number,i;
	
	printf("Enter the length of array: ");
	scanf("%d",&number);
	int array[number];
	for(i=0;i<number;i++){
		printf("Enter a number %d: ",i+1);
		scanf("%d",&array[i]);
	}
	for(i=1;i<number; i++){0
		if(array[0]<array[i]){
			array[0]=array[i];
		}
	}
	printf("The largest element of an array: %d",array[0]);
	return 0;
}

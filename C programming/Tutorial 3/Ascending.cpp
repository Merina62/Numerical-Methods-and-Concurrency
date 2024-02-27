#include<stdio.h>
int main(){
	int array[]={10,5,2,15,4};
	int temp;
	int i,j;
	int length= sizeof(array)/sizeof(array[0]);
	printf("The elements of original array: \n");
	for(i=0;i<length; i++){
		printf("%d ", array[i]);
	}
	for(i=0;i<length;i++){
		for(j=i+1;j<length;j++){
			if(array[i]>array[j]){
				temp= array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
	printf("\n");
	printf("The elements of an array after sorting the elements in ascending order is: \n");
	for(i=0;i<length;i++){
		printf("%d ",array[i]);
}
return 0;
}

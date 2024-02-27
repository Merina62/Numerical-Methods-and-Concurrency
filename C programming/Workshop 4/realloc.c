#include <stdio.h>
#include <stdlib.h>
void main(){
	int n,i;
	int *ptr;
	printf("Enter the size of an element ");
	scanf("%d",&n);
	// dynamic allocation
	ptr = (int*) malloc (n*sizeof(int));
	if(ptr==NULL){
		printf("Memory cananot be allocated.");
		exit(1);
	}
	//user input
	for(i = 0; i<n; i++){
		printf("Enter the element for index %d: ",i);
		scanf("%d",ptr+i);
		
	}
	
	//printing the entered elements
	for(i=0;i<n;i++){
		printf("\nEntered elements are index:%d memory address: %p value", i, ptr+i,*(ptr+i));
	}
	int new_size;
	printf("\nEnter new size: ");
	scanf("%d",&new_size);
	ptr=(int*) realloc(ptr,new_size*sizeof(int));
	for(i=n; i<n+new_size; i++){
		printf("Enter the elements for index %d: ",i);
		scanf("%d",ptr+1);
	}
	//final array
	printf("\nThe final array:\n");
	for(i=0;i<n+new_size;i++){
		printf("Index: %d \nmemory address: %d \nvalue: %d",i,ptr+i,*(ptr+i));
	}
	free(ptr);
	ptr=NULL;
}

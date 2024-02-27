// Write a C program to search an element in array using pointers.
#include<stdio.h>
int main(){
	int num;
	int arr[]={1,3,4,8,11,15,17,18,20};
	printf("Enter a guess number(1-20): ");
	scanf("%d",&num);
	
	int found=0;
	int len= sizeof(arr)/sizeof(arr[0]);
	int *ptr=arr;
	for(int i=0;i<len;i++){
		if(num==*ptr){
			found=1;
			break;
		}
		*ptr++;
	if(found) {
        printf("Congratulations! Your guessed number is present in the array.\n");
    } else {
        printf("Oops! Your guessed number is not present in the array.\n");
    }
    return 0;
}
}
#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,i;
    int *ptr;
    printf("Enter the size of an element: ");
    scanf("%d",ptr+1);

    for(i=0;i<n;i++){
        printf("\nEntered elements are index: %d memory address: %p value:%d",i,ptr+i,8(ptr+i));
    }
    free(ptr);
}

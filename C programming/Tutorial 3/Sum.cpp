#include<stdio.h>
int main(){
	int number,i;
	int array[10];
	for(i=0;i<10;++i){
		printf("Enter a number %d: ",i+1);
		scanf("%d",&array[i]);
	}
	for(i=0;i<10;i++){
		int sum=0;
		sum=sum+array[i];
	}
}


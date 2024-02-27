// Create a program to search an element from an array using multithreading. If the element
// is found print element found else print element not found.

#include<stdio.h>
#include<pthread.h>

int arr[8]={1,5,8,7,2,6,9,3};
int element;
int found=0;

void* One(void* arg){
	for(int i=0;i<10;i++){
		if(arr[i]==element){
			printf("Element %d found in the array.\n", element);
			break;
		} else{
			printf("Element %d not found in the array.\n", element);
			break;
		}
	}
	pthread_exit(NULL);
}



int main(){
	printf("Enter the element to search: ");
	scanf("%d",&element);
	pthread_t thread1;
	pthread_create(&thread1,NULL, One,NULL);
	
	pthread_join(thread1,NULL);
	
	
    return 0;
} 
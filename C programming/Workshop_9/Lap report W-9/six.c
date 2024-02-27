// Create a program to search an element from an array using multithreading. If the element
// is found print element found else print element not found.

#include<stdio.h>
#include<pthread.h>

int arr[10]={2,4,6,8,10,12,14,16,18,20};
int element;
int found=0;

void* First(void* arg){
	for(int i=0;i<5;i++){
		if(arr[i]==element){
			found=1;
			break;
		}
	}
	pthread_exit(NULL);
}

void* Second(void* arg){
	for(int i=5;i<10;i++){
		if(arr[i]==element){
			found=1;
			break;
		}
	}
	pthread_exit(NULL);
}


int main(){
	printf("Enter the element to search: ");
	scanf("%d",&element);
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL, First,NULL);
	pthread_create(&thread2,NULL, Second,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	 if (found) {
        printf("Element %d found in the array.\n", element);
    } else {
        printf("Element %d not found in the array.\n", element);
    }

    return 0;
} 
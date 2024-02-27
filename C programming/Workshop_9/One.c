// Write a program that creates two threads to display the
// numbers from 1-1000. The two threads should equally
// contribute to display the numbers.
int i,j;
#include<stdio.h>
#include<pthread.h>

void* One(void* args1){
	for(i=1;i<=500;i++){
		printf("\n%d",i);
	}
}

void* Two(void* args2){
	for(j=501;j<=1000;j++){
		printf("\n%d",j);
	}
}

int main(){
	pthread_t thread1;
	pthread_t thread2;
	
	//creating threads
	pthread_create(&thread1,NULL,One,NULL);
	pthread_create(&thread2,NULL,Two,NULL);
	
	//joining threads
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	pthread_exit(NULL);
	return 0;
	
}
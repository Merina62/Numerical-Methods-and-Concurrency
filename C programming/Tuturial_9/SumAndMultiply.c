#include<stdio.h>
#include<pthread.h>
int a=20,b=10,result;

void* add(void* arg1){
	result= a+b;
	printf("\nThe sum of %d and %d is %d",a,b,result);
}

void* multiply(void* arg2){
	result= a*b;
	printf("\nThe multiply of %d and %d is %d",a,b,result);
}

int main(){
	pthread_t thread1;
	pthread_t thread2;
	
	//Creating thread and run
	pthread_create(&thread1,NULL,add,NULL);
	
	pthread_create(&thread2, NULL,multiply,NULL);
	
	
	//processing threads
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	pthread_exit(NULL);
	return 0;
}
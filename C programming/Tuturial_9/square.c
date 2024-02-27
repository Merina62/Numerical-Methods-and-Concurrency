#include<stdio.h>
#include<pthread.h>
int a=5,result;
void* square(void* arg){
	result= a*a;
	printf("The square of %d is %d",a,result);
}
int main(){
	// initializing thread
	pthread_t thread1;
	//create thread and run
	pthread_create(&thread1,NULL,square,NULL);
	//processing thread
	pthread_join(thread1,NULL);
	//exiting thread
	pthread_exit(NULL);	
	return 0;
}


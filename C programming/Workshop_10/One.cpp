#include<stdio.h>
#include<pthread.h>
int count=0;
void* fun(void* arg){
	count++;//1 //2
	int i;
	printf("Thread %d has started\n",count);
	for(i=1;i<=1000000;i++){ }
	printf("Thread %d has finished\n",count);
}
void main(){
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,fun,NULL);
	pthread_create(&thread2,NULL,fun,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
}
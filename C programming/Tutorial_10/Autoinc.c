#include<stdio.h>
#include<pthread.h>
int a=0;
pthread_mutex_t mutex;
void* autoincrement(void* arg){
	
	for(int i=0;i<=100;i++){
		pthread_mutex_lock(&mutex);
		a++;
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}
int main(){
	pthread_t thread[5];
	if(pthread_mutex_init(&mutex,NULL)!=0){
		printf("Mutex Initialization failed!");
		return 1;
	}
	for(int i=0;i<=4;i++){
		if(pthread_create(&thread[i],NULL,autoincrement,NULL)!=0){
			printf("Failed to create thread!");
			return 2;
		}
	}
	for(int i=0;i<=4;i++){
		if(pthread_join(thread[i],NULL)!=0){
			printf("Thread Processing Failed!");
			return 3;
		}
	}
	printf("The autoincremented value of a is %d",a);
	if(pthread_mutex_destroy(&mutex)!=0){
		printf("Mutex destruction failed!");
		return 4;
	}
	return 0;
}

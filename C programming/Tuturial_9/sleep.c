#include<stdio.h>
#include<pthread.h>

void* first(void* arg1);
//void* second(void* arg2);


int second(){
	Sleep(1000);
	while(1){
		printf("\nThis is second thread");
	}
}

int main(){
	pthread_t thread1;
	pthread_t thread2;
	
	//creating threads
	pthread_create(&thread1,NULL, first, NULL);
//	pthread_create(&thread2, NULL, second, NULL);
	second();
	
	//processing threads
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	pthread_exit(NULL);
	return 0;
	
	
	
}

void* first(void* arg1){
	Sleep(1000);
	while(1){
		printf("\nThis is first thread");
	}
}

//void* second(void* arg2){
//	Sleep(1000);
//	while(1){
//		printf("\nThis is second thread");
//	}
//}




// Write a program that creates 5 threads to display the
//numbers from 1-1000.The five threads should equally
//contribute to display the numbers.

#include<stdio.h>
#include<pthread.h>
int i,j,k,n,m;

void* One(void* arg1){
	for(i=1;i<=200;i++){
		printf("\n%d",i);
	}
}
void* Two(void* arg2){
	for(j=201;j<=400;j++){
		printf("\n%d",j);
	}
}

void* Three(void* arg2){
	for(k=401;k<=600;k++){
		printf("\n%d",k);
	}
}

void* Four(void* arg4){
	for(m=601;m<=800;m++){
		printf("\n%d",m);
	}
}

void* Five(void* arg5){
	for(n=801;n<=1000;n++){
		printf("\n%d",n);
	}
}


int main(){
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;
	pthread_t thread5;
	
	//creating threads
	pthread_create(&thread1,NULL, One, NULL);
	pthread_create(&thread2,NULL, Two, NULL);
	pthread_create(&thread3,NULL, Three, NULL);
	pthread_create(&thread4,NULL, Four, NULL);
	pthread_create(&thread5,NULL, Five, NULL);
	
	//joining threads
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
	pthread_join(thread4,NULL);
	pthread_join(thread5,NULL);
	
	pthread_exit(NULL);
	return 0;
}
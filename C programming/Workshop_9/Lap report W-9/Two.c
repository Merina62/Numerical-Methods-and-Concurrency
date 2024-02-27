// Write a program that creates two threads to display all the prime numbers from 1-500.
// The two threads should equally contribute to display the numbers.

#include<stdio.h>
#include<pthread.h>

int i,j,k,l;
void* One(void* args1){
	for(i=2;i<=250;i++){
		int isPrime=1;
		for(j=2;j<=i/2;j++){
			if(i%j==0){
				isPrime=0;
				break;
			}
		}
		if(isPrime){
			printf("\n%d",i);
		}
	}
}

void* Two(void* args2){
	for(k=251;k<=500;k++){
		int isPrime=1;
		for(l=2;l<=k/2;l++){
			if(k%l==0){
				isPrime=0;
				break;
			}
		}
		if(isPrime){
			printf("\n%d",k);
		}
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


// Finding maximum in an array using dynamic memory allocation.
# include<stdio.h>
# include<stdlib.h>

int maxNum(int *arr, int size){
	int max= arr[0];
	for(int i=1; i<size;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}

int main(){
	int size;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	
	int *arr= (int*) malloc(size * sizeof(int));
	if(arr== NULL){
		printf("Memory allocation failed.\n");
		return 1;
	}
	for(int i=0;i<size;i++){
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	int maxnum= maxNum(arr,size);
	printf("Maximum Element: %d",maxnum);
	
	free(arr);
	return 0;
}


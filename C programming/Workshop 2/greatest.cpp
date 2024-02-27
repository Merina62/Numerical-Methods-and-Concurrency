# include <stdio.h>
int greatest(int a,int b){
	if(a>b){
		return a;
	} else{
		return b;
	}
}
int main(){
	int x,y;
	printf("Enter first number: ");
	scanf("%d",&x);
	printf("Enter second number: ");
	scanf("%d",&y);
	
	int G= greatest(x,y);
	printf("The greatest number is : %d",G);
	return 0;
}


# include <stdio.h>

void triangular(int n){
	int sum=0;
	for(int i=1; i<=n; i++){
		sum+=i;
		printf("Triangular number &d is %d \n",i,sum);
	}
}
int main(){
	int n;
	printf("Enter a number to find the triangular number: ");
	scanf("%d", &n);
	triangular(n);
	return 0;
}


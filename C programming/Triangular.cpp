# include <stdio.h>
//int main(){
//	int n,i,j,t;
//	printf("Enter a number: ");
//	scanf("%d", &n);
//	if(n<=0){
//		printf("Please enter a positive integer\n ");
//		return 1;
//	}
//	for(i=1;i<=n;i++){
//		int t=0;
//		for(j=1;j<=i; j++){
//			t+=j;
//		}	
//		printf("Triangular number %d: %d \n",i,t);
//	}
//	return 0;
//}

int main() {
    int n, i, j, t;

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &n);

        if (n > 0) {
            break; // Exit the loop if n is positive
        } else {
            printf("Please enter a positive integer\n");
        }
    }

    for (i = 1; i <= n; i++) {
        t = 0;
        for (j = 1; j <= i; j++) {
            t += j;
        }
        printf("Triangular number %d: %d \n", i, t);
    }

    return 0;
}


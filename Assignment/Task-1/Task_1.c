// Load necessary libraries
#include<stdio.h>
#include<math.h>

void calculate(FILE *fptr, float *sumX, float *sumY, float *sumXY, float *sumXsquare, int *n){
	// Declare Variables
	int x,y;
	// Reading the data until the end of file
	while (fscanf(fptr, "%d, %d", &x, &y) != EOF)
    {
    	//Update each value by adding
        (*sumX) += x;
        (*sumY) += y;
        (*sumXsquare) += pow(x, 2);
        (*sumXY) += (x*y);
        (*n)++;
    }
}

//Defining main function
int main(){
	//Declare an array of four file pointers
	FILE *fptr[4];
	//Opening files in read mode and checking if there is any error while opening the files
    fptr[0] = fopen("datasetLR1.txt", "r");
    if(fptr[0]==NULL){
    	printf("Error opening datasetLR1.txt");
	}
    fptr[1] = fopen("datasetLR2.txt", "r");
    if(fptr[1]==NULL){
    	printf("Error opening datasetLR1.txt");
	}
    fptr[2] = fopen("datasetLR3.txt", "r");
    if(fptr[2]==NULL){
    	printf("Error opening datasetLR1.txt");
	}
    fptr[3] = fopen("datasetLR4.txt", "r");
    if(fptr[3]==NULL){
    	printf("Error opening datasetLR1.txt");
	}
    
    //Decalre and initialize the variables
    float sumX=0, sumY=0, sumXY=0, sumXsquare=0;
    int n=0;
    // Loop iterating for each files
    for(int i=0;i<4;i++){
    	// Calculate the parameters
    	calculate(fptr[i], &sumX, &sumY, &sumXY, &sumXsquare, &n);
	}
	
	// formula for calculating the value of A and B
	float A=((sumY*sumXsquare)-(sumX*sumXY))/((n*sumXsquare)-pow(sumX, 2));
    float B = ((n*sumXY)-(sumX*sumY))/((n*sumXsquare)-pow(sumX, 2));
    
    // Printing the values 
    printf("A = %0.2f\n",A);
    printf("B = %0.2f\n",B);
    
    //printing the equation
    printf("Equation of the straight line is y = %.2fx + %.2f\n", A, B);
    
    float user_x;
    // User input for x
    printf("\nEnter x coordinate to predict y: ");
    scanf("%f", &user_x);\
    
	// Finding the predicted y value
    float y_Pred = B*user_x+A;

	//printing the value of x
    printf("The value of x = %0.2f", user_x);
	
	//printing thr y predicted value
    printf("\nThe predicted result is y = %0.2f\n", y_Pred);
	printf("%d",n);
	// Executing the loop to colse all file
    for (int i = 0; i < 4; i++)
        fclose(fptr[i]);

    return 0;
    
}

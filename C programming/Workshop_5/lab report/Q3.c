// Write a program that asks the user for two inputs: lower limit and upper limit. Now
// write a function named display that prints all the numbers between those limits.
// NOTE: You are only allowed to pass one parameter to the function and lower limit
// and upper limit variables should not be made global.in
#include<stdio.h>

// Structure to hold lower and upper limits
struct Limits {
    int lower;
    int upper;
};

// Function declaration
void display(struct Limits limits);

int main() {
    struct Limits userLimits;

    // Get user input
    printf("Enter the number for lower limit: ");
    scanf("%d", &userLimits.lower);
    
    printf("Enter the number for upper limit: ");
    scanf("%d", &userLimits.upper);
    
    // Call the display function
    display(userLimits);

    return 0;
}

void display(struct Limits limits) {
    // Check if lower limit is greater than upper limit
    if (limits.lower > limits.upper) {
        printf("Invalid input: Lower limit is greater than upper limit.\n");
        return;
    }

    // Display numbers between lower and upper limits
    printf("Numbers between %d and %d are:\n", limits.lower, limits.upper);
    for (int i = limits.lower; i <= limits.upper; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

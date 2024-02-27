// C program to create memory for int, char and float variables at run time.
#include<stdio.h>
#include<stdlib.h>

int main() {
    int *ptr_int;
    char *ptr_char;
    float *ptr_float;

    ptr_int = (int*) malloc(sizeof(int));
    if(ptr_int == NULL) {
        printf("Memory cannot be allocated.");
        exit(1);
    }

    ptr_char = (char*) malloc(sizeof(char));
    if(ptr_char == NULL) {
        printf("Memory cannot be allocated.");
        exit(1);
    }

    ptr_float = (float*) malloc(sizeof(float));
    if(ptr_float == NULL) {
        printf("Memory cannot be allocated.");
        exit(1);
    }

    *ptr_int = 4;
    *ptr_char = 'M';
    *ptr_float = 55.22;

    printf("Int Variable: %d\n", *ptr_int);
    printf("Char Variable: %c\n", *ptr_char);
    printf("Float Variable: %.2f\n", *ptr_float);

    free(ptr_int);
    free(ptr_char);
    free(ptr_float);
    return 0;
}

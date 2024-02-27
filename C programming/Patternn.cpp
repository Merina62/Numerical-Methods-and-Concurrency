#include <stdio.h>

int main() {
    int n = 5;  // Number of rows

    // Outer loop for each row
    for (int i = 0; i < n; i++) {
        // Inner loop for each column in the current row
        for (int j = 0; j <= i; j++) {
            // Print the character corresponding to the row (A = 65 in ASCII)
            printf("%c ", 'A' + i);
        }
        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}


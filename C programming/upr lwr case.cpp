#include <stdio.h>
#include <ctype.h>

int main() {
    char c;

    printf("Enter characters (press Enter to stop): ");

    while (1) {
        // Read a character
        scanf(" %c", &c); // Adding a space before %c to consume any leading whitespace

        // Check if Enter key is pressed
        if (c == '\n') {
            break;
        }

        // Check if the character is uppercase and convert to lowercase if needed
        if (isupper(c)) {
            c = tolower(c);
        }

        // Print the character
        printf("%c", c);
    }

    return 0;
}


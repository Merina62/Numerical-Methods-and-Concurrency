#include <stdio.h>
#include <string.h>

// Function to check if two strings are anagrams
int areAnagrams(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If lengths are not equal, the strings cannot be anagrams
    if (len1 != len2) {
        return 0; // Not anagrams
    }

    // Sort both strings
    for (int i = 0; i < len1 - 1; i++) {
        for (int j = i + 1; j < len1; j++) {
            if (str1[i] > str1[j]) {
                // Swap characters
                char temp = str1[i];
                str1[i] = str1[j];
                str1[j] = temp;
            }
            if (str2[i] > str2[j]) {
                // Swap characters
                char temp = str2[i];
                str2[i] = str2[j];
                str2[j] = temp;
            }
        }
    }

    // Compare sorted strings
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return 0; // Not anagrams
        }
    }

    return 1; // Anagrams
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // Check if the strings are anagrams
    if (areAnagrams(str1, str2)) {
        printf("The given strings are anagrams.\n");
    } else {
        printf("The given strings are not anagrams.\n");
    }

    return 0;
}


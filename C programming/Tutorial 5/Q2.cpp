//Design a structure called Book with members title, author. ISBN and price. Write a program to input details of five books from the user
//and store them in an arry of structures. Implement a function to display the details of a book given its ISBN number.

#include <stdio.h>

struct Book {
    char title[100];
    char author[100];
    int ISBN;
    float price;
};

void displayBookDetails(struct Book books[], int n, int isbn) {
    int i;
    for (i = 0; i < n; i++) {
        if (books[i].ISBN == isbn) {
            printf("Book Details:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("ISBN: %d\n", books[i].ISBN);
            printf("Price: $%.2f\n", books[i].price);
            return;
        }
    }
    printf("Book with ISBN %d not found.\n", isbn);
}

int main() {
    struct Book books[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Enter details for Book %d:\n", i + 1);
        printf("Title: ");
        scanf("%s", books[i].title);
        printf("Author: ");
        scanf("%s", books[i].author);
        printf("ISBN: ");
        scanf("%d", &books[i].ISBN);
        printf("Price: $");
        scanf("%f", &books[i].price);
        printf("\n");
    }

    int isbn;
    printf("Enter ISBN number to display book details: ");
    scanf("%d", &isbn);

    displayBookDetails(books, 5, isbn);

    return 0;
}
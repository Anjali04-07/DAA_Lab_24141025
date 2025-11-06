#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Structure to hold book information
struct Book {
    char title[100];
    char isbn[20];
    char author[50];
}
// Convert a string to lowercase for case-insensitive comparison
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }}
// Binary Search function to find a book by title
int binarySearch(struct Book books[], int n, char target[]) {
    int low = 0, high = n - 1;
    char targetLower[100];
    strcpy(targetLower, target);
    toLowerCase(targetLower);
    while (low <= high) {
        int mid = (low + high) / 2;
       char midTitle[100];
        strcpy(midTitle, books[mid].title);
        toLowerCase(midTitle);
        int cmp = strcmp(midTitle, targetLower);
        if (cmp == 0)
            return mid; // Found
        else if (cmp < 0)
            low = mid + 1; // Search in right half
        else
            high = mid - 1; // Search in left half
    }
    return -1; // Not found
}
int main() {
    // Predefined sorted list of books (sorted alphabetically by title)
    struct Book books[] = {
        {"A Tale of Two Cities", "9781853260391", "Charles Dickens"},
        {"Animal Farm", "9780451526342", "George Orwell"},
        {"Harry Potter and the Sorcerer's Stone", "9780439708180", "J.K. Rowling"},
        {"Moby Dick", "9781503280786", "Herman Melville"},
        {"Pride and Prejudice", "9781503290563", "Jane Austen"},
        {"The Great Gatsby", "9780743273565", "F. Scott Fitzgerald"},
        {"To Kill a Mockingbird", "9780060935467", "Harper Lee"}
    };
    int n = sizeof(books) / sizeof(books[0]);
    char searchTitle[100];
    printf("========================================\n");
    printf("        Book Finder Application         \n");
    printf("========================================\n")
    printf("\nEnter the book title you want to search for: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);
    // Remove newline character from input
    searchTitle[strcspn(searchTitle, "\n")] = '\0';
    int result = binarySearch(books, n, searchTitle);
    if (result != -1) {
        printf("\nBook Found!\n");
        printf("-------------------------\n");
        printf("Title : %s\n", books[result].title);
        printf("ISBN  : %s\n", books[result].isbn);
        printf("Author: %s\n", books[result].author);
    } else {
        printf("\nBook not found in the library database.\n");
    }
    printf("\nThank you for using the Book Finder System.\n");
    printf("========================================\n");
    return 0;
}

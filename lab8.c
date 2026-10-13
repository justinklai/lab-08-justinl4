#include <stdio.h>
#define SIZE 8

void displayBooks(int books[], int size);
int countAvailable(int books[], int size);
int checkoutBook(int books[], int size, int bookID);
int returnBook(int books[], int size, int bookID);
int findFirstAvailable(int books[], int size);

int main(void)
{
    int books[SIZE] = {0, 1, 0, 0, 1, 0, 1, 0};
    int bookID;
    int available;

    // Part 1: display
    displayBooks(books, SIZE);

    // Part 2: count
    available = countAvailable(books, SIZE);
    printf("\nAvailable books: %d\n", available);
    printf("Checked-out books: %d\n", SIZE - available);

    /* Optional challenge */
    int first = findFirstAvailable(books, SIZE);
    if (first == -1)
        printf("No books available.\n");
    else
        printf("First available book: %d\n", first);

    // Part 3
    printf("\nEnter book ID to check out: ");
    scanf("%d", &bookID);

    if (bookID < 0 || bookID >= SIZE)
    {
        printf("Invalid book ID.\n");
    }
    else if (checkoutBook(books, SIZE, bookID) == 1)
    {
        printf("Book %d checked out successfully.\n", bookID);
    }
    else
    {
        printf("Book is already checked out.\n");
    }

    // Part 4
    printf("\nEnter book ID to return: ");
    scanf("%d", &bookID);

    if (bookID < 0 || bookID >= SIZE)
    {
        printf("Invalid book ID.\n");
    }
    else if (returnBook(books, SIZE, bookID) == 1)
    {
        printf("Book %d returned successfully.\n", bookID);
    }
    else
    {
        printf("Book is already available.\n");
    }
//Optional
printf(findFirstAvailable(books, SIZE) == -1 ? "No books available.\n" : "First available book: %d\n", findFirstAvailable(books, SIZE));

    return 0;
}

void displayBooks(int books[], int size)
{
    int i;
    printf("Library Book Status:\n");
    for (i = 0; i < size; i++)
    {
        printf("Book %d: %s\n", i, books[i] == 0 ? "Available" : "Checked out");
    }
}

int countAvailable(int books[], int size)
{
    int i, count = 0;
    for (i = 0; i < size; i++)
    {
        if (books[i] == 0)
            count++;
    }
    return count;
}

int checkoutBook(int books[], int size, int bookID)
{
    if (bookID < 0 || bookID >= size)
        return 0;
    if (books[bookID] == 0)
    {
        books[bookID] = 1;
        return 1;
    }
    return 0;
}

int returnBook(int books[], int size, int bookID)
{
    if (bookID < 0 || bookID >= size)
        return 0;
    if (books[bookID] == 1)
    {
        books[bookID] = 0;
        return 1;
    }
    return 0;
}

int findFirstAvailable(int books[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (books[i] == 0)
            return i;
    }
    return -1;
}
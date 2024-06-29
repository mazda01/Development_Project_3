#include <stdio.h>
#include <string.h>

void addBook();
void DisplayAvailableBooks();
void borrowBook();
void returnBook();
void searchBooksByTitle();
void searchBooksByAuthor();

char titles[5][100];
char authors[5][100];
int availability[5];
int bookCount = 0;

int main()
{
    int choice;
    char input[10];

    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Display Available Books\n");
    printf("3. Borrow Book\n");
    printf("4. Return Book\n");
    printf("5. Search Books by Title\n");
    printf("6. Search Books by Author\n");
    printf("0. Exit\n");
    do
    {
        printf("\033[0;33m\nEnter your choice: \033[0m");
        scanf("%s", input);
        choice = -1;

        if (strlen(input) == 1 && input[0] >= '0' && input[0] <= '6')
        {
            choice = input[0] - '0';
        }
        else
        {
            printf("\033[0;31mInvalid choice. Please try again.\033[0m\n");
            continue;
        }

        if (choice == 1)
        {
            addBook();
        }
        else if (choice == 2)
        {
            DisplayAvailableBooks();
        }
        else if (choice == 3)
        {
            borrowBook();
        }
        else if (choice == 4)
        {
            returnBook();
        }
        else if (choice == 5)
        {
            searchBooksByTitle();
        }
        else if (choice == 6)
        {
            searchBooksByAuthor();
        }
        else if (choice == 0)
        {
            printf("Exiting the system.\n");
        }
    } while (choice != 0);

    return 0;
}
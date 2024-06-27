#include <stdio.h>
#include <string.h>

char titles[5][100];
char authors[5][100];
int availability[5];
int bookCount = 0;

void addBook()
{
    char tempTitle[100];
    char tempAuthor[100];
    int titleIsNumber, authorIsNumber;

    if (bookCount < 5)
    {
        do
        {
            titleIsNumber = 0;
            printf("Enter book title: ");
            scanf(" %[^\n]%*c", tempTitle);

            for (int i = 0; tempTitle[i] != '\0'; i++)
            {
                if (tempTitle[i] >= '0' && tempTitle[i] <= '9')
                {
                    titleIsNumber = 1;
                    break;
                }
            }

            if (titleIsNumber)
            {
                printf("Invalid input. Please enter a valid book title.\n");
            }
        } while (titleIsNumber);

        strncpy(titles[bookCount], tempTitle, 99);
        titles[bookCount][99] = '\0';

        do
        {
            authorIsNumber = 0;
            printf("Enter author name: ");
            scanf(" %[^\n]%*c", tempAuthor);

            for (int i = 0; tempAuthor[i] != '\0'; i++)
            {
                if (tempAuthor[i] >= '0' && tempAuthor[i] <= '9')
                {
                    authorIsNumber = 1;
                    break;
                }
            }

            if (authorIsNumber)
            {
                printf("Invalid input. Please enter a valid author name.\n");
            }
        } while (authorIsNumber);

        strncpy(authors[bookCount], tempAuthor, 99);
        authors[bookCount][99] = '\0';

        availability[bookCount] = 1;
        bookCount++;

        printf("Book added successfully.\n");
    }
    else
    {
        printf("Library is full, cannot add more books.\n");
    }
}

void displayAvailableBooks()
{
    int found = 0;
    int i = 0;
    while (i < bookCount)
    {
        if (availability[i])
        {
            printf("Title: %s, Author: %s\n", titles[i], authors[i]);
            found = 1;
        }
        i++;
    }
    if (!found)
    {
        printf("No available books.\n");
    }
}

void borrowBook()
{
    char title[100];
    printf("Enter the title of the book to borrow: ");
    scanf(" %[^\n]%*c", title);

    int i = 0;
    while (i < bookCount)
    {
        if (strcmp(titles[i], title) == 0)
        {
            if (availability[i])
            {
                availability[i] = 0;
                printf("You borrowed the book: %s\n", title);
                return;
            }
            else
            {
                printf("The book is already borrowed.\n");
                return;
            }
        }
        i++;
    }
    printf("The book was not found.\n");
}

void returnBook()
{
    char title[100];
    printf("Enter the title of the book to return: ");
    scanf(" %[^\n]%*c", title);

    int i = 0;
    while (i < bookCount)
    {
        if (strcmp(titles[i], title) == 0)
        {
            if (!availability[i])
            {
                availability[i] = 1;
                printf("You returned the book: %s\n", title);
                return;
            }
            else
            {
                printf("The book was not borrowed.\n");
                return;
            }
        }
        i++;
    }
    printf("The book was not found.\n");
}

void searchBooksByTitle()
{
    char title[100];
    printf("Enter the title to search for: ");
    scanf(" %[^\n]%*c", title);

    int found = 0;
    int i = 0;
    while (i < bookCount)
    {
        if (strstr(titles[i], title) != NULL)
        {
            printf("Title: %s, Author: %s, Available: %s\n", titles[i], authors[i], availability[i] ? "Yes" : "No");
            found = 1;
        }
        i++;
    }
    if (!found)
    {
        printf("No books found with the title containing '%s'.\n", title);
    }
}

void searchBooksByAuthor()
{
    char author[100];
    printf("Enter the author to search for: ");
    scanf(" %[^\n]%*c", author);

    int found = 0;
    int i = 0;
    while (i < bookCount)
    {
        if (strstr(authors[i], author) != NULL)
        {
            printf("Title: %s, Author: %s, Available: %s\n", titles[i], authors[i], availability[i] ? "Yes" : "No");
            found = 1;
        }
        i++;
    }
    if (!found)
    {
        printf("No books found by the author '%s'.\n", author);
    }
}

int main()
{
    int choice;
    char input[10];

    do
    {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Available Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Search Books by Title\n");
        printf("6. Search Books by Author\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        scanf("%s", input);
        choice = -1;

        if (strlen(input) == 1 && input[0] >= '0' && input[0] <= '6')
        {
            choice = input[0] - '0';
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        if (choice == 1)
        {
            addBook();
        }
        else if (choice == 2)
        {
            displayAvailableBooks();
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
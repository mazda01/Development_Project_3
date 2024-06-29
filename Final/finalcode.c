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

int isOnlyDigits(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void addBook()
{
    char tempTitle[100];
    char tempAuthor[100];
    int titleIsNumber, authorIsNumber;
    int i;

    if (bookCount < 5)
    {
        do
        {
            titleIsNumber = 1;
            printf("Enter book title: ");
            scanf(" %[^\n]%*c", tempTitle);

            i = 0;
            while (tempTitle[i] != '\0')
            {
                if ((tempTitle[i] < '0' || tempTitle[i] > '9') && tempTitle[i] != ' ')
                {
                    titleIsNumber = 0;
                    break;
                }
                i++;
            }

            if (titleIsNumber)
            {
                printf("\033[0;31mInvalid input. Please enter a valid book title.\033[0m\n");
            }
        } while (titleIsNumber);

        strncpy(titles[bookCount], tempTitle, 99);
        titles[bookCount][99] = '\0';

        do
        {
            authorIsNumber = 0;
            printf("Enter author name: ");
            scanf(" %[^\n]%*c", tempAuthor);

            i = 0;
            while (tempAuthor[i] != '\0')
            {
                if (tempAuthor[i] >= '0' && tempAuthor[i] <= '9')
                {
                    authorIsNumber = 1;
                    break;
                }
                i++;
            }

            if (authorIsNumber)
            {
                printf("\033[0;31mInvalid input. Please enter a valid author name.\033[0m\n");
            }
        } while (authorIsNumber);

        strncpy(authors[bookCount], tempAuthor, 99);
        authors[bookCount][99] = '\0';

        availability[bookCount] = 1;
        bookCount++;

        printf("\033[0;32mBook added successfully.\033[0m\n");
    }
    else
    {
        printf("\033[0;31mLibrary is full, cannot add more books.\033[0m\n");
    }
}

void DisplayAvailableBooks()
{
    int found = 0;
    int i;
    printf("\n============================================");
    printf("\nTitle  \t \t            Author");
    printf("\n=============================================\n");
    for (i = 0; i < bookCount; i++)
    {
        if (availability[i])
        {
            printf("%s    \t \t           %s\n", titles[i], authors[i]);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\033[0;31mNo available books.\033[0m\n");
    }
    printf("===============================================\n");
}

void borrowBook()
{
    char title[100];
    int isDigits;
    int i;

    do
    {
        printf("Please enter the title of the book you want to borrow: ");
        scanf(" %[^\n]%*c", title);
        isDigits = isOnlyDigits(title);
        if (isDigits)
        {
            printf("\033[0;31mInvalid input. Title cannot be only digits.\033[0m\n");
        }
    } while (isDigits);

    i = 0;
    while (i < bookCount)
    {
        if (strcmp(titles[i], title) == 0)
        {
            if (availability[i])
            {
                availability[i] = 0;
                printf("\033[0;32mYou have successfully borrowed:\033[0m\n");
                printf("\n============================================");
                printf("\nTitle  \t \t            Author");
                printf("\n=============================================\n");
                printf("%s    \t \t           %s\n", titles[i], authors[i]);
                return;
            }
            else
            {
                printf("\033[0;31mThe book is already borrowed.\033[0m\n");
                return;
            }
        }
        i++;
    }
    printf("\033[0;31mThe book was not found.\033[0m\n");
}

void returnBook()
{
    char title[100];
    int isDigits;
    int i;

    do
    {
        printf("Enter the title of the book to return: ");
        scanf(" %[^\n]%*c", title);
        isDigits = isOnlyDigits(title);
        if (isDigits)
        {
            printf("\033[0;31mInvalid input. Title cannot be only digits.\033[0m\n");
        }
    } while (isDigits);

    i = 0;
    while (i < bookCount)
    {
        if (strcmp(titles[i], title) == 0)
        {
            if (!availability[i])
            {
                availability[i] = 1;
                printf("\033[0;32mYou returned the book:\033[0m\n");
                printf("\n============================================");
                printf("\nTitle  \t \t            Author");
                printf("\n=============================================\n");
                printf("%s    \t \t           %s\n", titles[i], authors[i]);
                return;
            }
            else
            {
                printf("\033[0;31mThe book was not borrowed.\033[0m\n");
                return;
            }
        }
        i++;
    }
    printf("\033[0;31mThe book was not found.\033[0m\n");
}

void searchBooksByTitle()
{
    char title[100];
    int isDigits;
    int found = 0;
    int i;

    do
    {
        printf("Enter the title to search for: ");
        scanf(" %[^\n]%*c", title);
        isDigits = isOnlyDigits(title);
        if (isDigits)
        {
            printf("\033[0;31mInvalid input. Title cannot be only digits.\033[0m\n");
        }
    } while (isDigits);

    for (i = 0; i < bookCount; i++)
    {
        if (strncmp(titles[i], title, strlen(title)) == 0)
        {
            printf("\n============================================");
            printf("\nTitle  \t \t            Author");
            printf("\n=============================================\n");
            printf("%s    \t \t           %s\n", titles[i], authors[i]);
            printf("Available: %s\n", availability[i] ? "Yes" : "No");
            found = 1;
        }
    }
    if (!found)
    {
        printf("\033[0;31mNo books found with the title starting with '%s'.\033[0m\n", title);
    }
}

void searchBooksByAuthor()
{
    char author[100];
    int isDigits;
    int found = 0;
    int i;

    do
    {
        printf("Enter the author to search for: ");
        scanf(" %[^\n]%*c", author);
        isDigits = isOnlyDigits(author);
        if (isDigits)
        {
            printf("\033[0;31mInvalid input. Author name cannot be only digits.\033{0m\n");
        }
    } while (isDigits);

    for (i = 0; i < bookCount; i++)
    {
        if (strncmp(authors[i], author, strlen(author)) == 0)
        {
            printf("\n============================================");
            printf("\nTitle  \t \t            Author");
            printf("\n=============================================\n");
            printf("%s    \t \t           %s\n", titles[i], authors[i]);
            printf("Available: %s\n", availability[i] ? "Yes" : "No");
            found = 1;
        }
    }
    if (!found)
    {
        printf("\033[0;31mNo books found by the author starting with '%s'.\033[0m\n", author);
    }
}
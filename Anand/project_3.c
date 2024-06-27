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

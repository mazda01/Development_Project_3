#include <stdio.h>
#include <string.h>

char titles[5][100];
char authors[5][100];
int availability[5];
int bookCount = 0;

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

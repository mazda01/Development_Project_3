#include <stdio.h>
#include <string.h>

char titles[5][100];
char authors[5][100];
int availability[5];
int bookCount = 0;

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
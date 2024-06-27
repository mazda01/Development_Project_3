#include <stdio.h>
#include <string.h>

char titles[5][100];
char authors[5][100];
int availability[5];
int bookCount = 0;

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
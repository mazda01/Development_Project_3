#include <stdio.h>
#include <string.h>

char titles[5][100];
char authors[5][100];
int availability[5];
int bookCount = 0;

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
            printf("\033[0;31mInvalid input. Author name cannot be only digits.\033[0m\n");
        }
    } while (isDigits);

    for (i = 0; i < bookCount; i++)
    {
        if (strcmp(authors[i], author, strlen(author)) == 0)
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
        printf("\033[0;31mNo books found by the author '%s'.\033[0m\n", author);
    }
}
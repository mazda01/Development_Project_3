#include <string.h>

char titles[5][100];
char authors[5][100];
int availability[5];
int bookCount = 0;

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
        printf("\033[0;31mNo books found with the title containing '%s'.\033[0m\n", title);
    }
}

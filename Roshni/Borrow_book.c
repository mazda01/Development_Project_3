#include <stdio.h>
#include <string.h>
void borrowBook();
char titles[5][100];
char authors[5][100];
int availability[5];
int bookCount = 0;
int main()
{
     borrowBook();
     return 0;
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
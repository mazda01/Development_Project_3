#include <stdio.h>
#include <string.h>

char titles[5][100];
char authors[5][100];
int availability[5];
int bookCount = 0;

int main()
{
    return 0;

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
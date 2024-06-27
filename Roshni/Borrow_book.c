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
    printf("Please enter the title of the book you want to borrow: ");
    scanf(" %[^\n]%*c", title);

    int i = 0;
    while (i < bookCount)
    {
        if (strcmp(titles[i], title) == 0)
        {
            if (availability[i])
            {
                availability[i] = 0;
                printf("You have successfully borrowed : \n");
                printf("Title\t Author\n");
                printf("%s\t %s\n", titles, authors);
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

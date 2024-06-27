#include<stdio.h>
#include<string.h>

char titles[5][100];
char authors[5][100];
int availability[5];
int bookCount = 0;

void addBook();
int main()
{
    
    addBook();

    return 0;
}
void addBook()
{
    if (bookCount < 5)
    {
        printf("Enter book title: ");
        scanf(" %[^\n]%*c", titles[bookCount]);

        printf("Enter author name: ");
        scanf(" %[^\n]%*c", authors[bookCount]);

        availability[bookCount] = 1;
        bookCount++;

        printf("Book Added Successfully!\n");
    }   
    else
    {
        printf("Library is full, cannot add more books.\n");
    }
}
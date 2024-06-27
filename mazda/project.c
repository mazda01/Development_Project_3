#include <stdio.h>
int choicenumber;
int authorName;
int TittleName;

int main()
{
    printf("************** Library Management System***********");
    printf("\n1-Add New Book");
    printf("\n2-Disply Available Books");
    printf("\n3-Borrow book");
    printf("\n4-Return Book");
    printf("\n5-Search Book by title");
    printf("\n6-Exit");

    while (1)
    {
        printf("\n\nplease enter the choice : ");
        scanf("%d", &choicenumber);
        if (choicenumber == 1)
        {
            
        }
        else if(choicenumber==2)
        {

        }
        else if(choicenumber==3)
        {

        }
        else if(choicenumber==4)
        {

        }
        else if(choicenumber==5)
        {

        }
        else if(choicenumber==0)
        {
            break;
        }
        else
        {
            printf("\ninvalid choice number");
        }
    }
    return 0;
}
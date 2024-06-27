void Displayavailablebooks();
int main()
{
    DisplayAvailableBooks();
    return 0;
}

void DisplayAvailableBooks()
{
    int found = 0;
    int i = 0;
    while (i < bookCount)
    {
        if (availability[i])
        {
    
            printf("Available Books: ");
            printf("\n============================================");
            printf("\nTitle  \t \t            Author");
            printf("\n=============================================");
            printf("\n%s    \t \t           %s\n", titles[i], authors[i]);
            printf("===============================================");
            found = 1;
        }
        i++;
    }
    if (!found)
    {
        printf("No available books.\n");
    }
}

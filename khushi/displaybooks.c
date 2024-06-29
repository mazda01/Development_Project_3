void DisplayAvailableBooks()
{
    int found = 0;
    int i;
    printf("\n============================================");
    printf("\nTitle  \t \t            Author");
    printf("\n=============================================\n");
    for (i = 0; i < bookCount; i++)
    {
        if (availability[i])
        {
            printf("%s    \t \t           %s\n", titles[i], authors[i]);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\033[0;31mNo available books.\033[0m\n");
    }
    printf("===============================================\n");
}
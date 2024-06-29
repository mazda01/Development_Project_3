
void returnBook()
{
    char title[100];
    int isDigits;
    int i;

    do
    {
        printf("Enter the title of the book to return: ");
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
            if (!availability[i])
            {
                availability[i] = 1;
                printf("\033[0;32mYou returned the book:\033[0m\n");
                printf("\n============================================");
                printf("\nTitle  \t \t            Author");
                printf("\n=============================================\n");
                printf("%s    \t \t           %s\n", titles[i], authors[i]);
                return;
            }
            else
            {
                printf("\033[0;31mThe book was not borrowed.\033[0m\n");
                return;
            }
        }
        i++;
    }
    printf("\033[0;31mThe book was not found.\033[0m\n");
}
#include <stdio.h>

int main()
{
    int i, j;
    char opt = 'C', op = '*';

    if (opt == 'A')
    {
        for (i = 1; i <= 10; i++)
        {
            for (j = 0; j < i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else if (opt == 'B')
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 10; j > i; j--)
            {
                printf("%c", op);
            }
            printf("\n");
        }
    }
    else if (opt == 'C')
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < i; j++)
            {
                printf(" ");
            }

            for (j = 10; j > i; j--)
            {
                printf("%c", op);
            }
            printf("\n");
        }
    }

    return 0;
}
#include <stdio.h>

int main()
{
    int num1, num2, num3, num4, num5, i;
    scanf("%i %i %i %i %i", &num1, &num2, &num3, &num4, &num5);

    for (i = 0; i < num1; i++)
        printf("*");
    printf("\n");

    for (i = 0; i < num2; i++)
        printf("*");
    printf("\n");

    for (i = 0; i < num3; i++)
        printf("*");
    printf("\n");

    for (i = 0; i < num4; i++)
        printf("*");
    printf("\n");

    for (i = 0; i < num5; i++)
        printf("*");
    printf("\n");
}
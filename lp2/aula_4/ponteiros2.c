#include <stdio.h>

void troca(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void preenche(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%i", &v[i]);
    }
}

int main()
{
    int a = 2, b = 3;
    printf("a = %i, b = %i\n", a, b);
    troca(&a, &b);
    printf("a = %i, b = %i\n", a, b);

    return 0;
}
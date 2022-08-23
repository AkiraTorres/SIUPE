#include <stdio.h>

int main()
{
    int *ponteiro;
    int numero = 6;

    ponteiro = &numero;

    printf("%p\n", ponteiro);
    printf("%p\n", ponteiro + 1);
    printf("%i\n", *ponteiro);

    return 0;
}
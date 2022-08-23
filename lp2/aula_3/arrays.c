#include <stdio.h>

#define MAX_CHAIRS 24

int main()
{
    int i, chairs[MAX_CHAIRS];
    long int cpf = -1;

    for (i = 0; i < MAX_CHAIRS; i++)
    {
        chairs[i] = 0;
    }

    while (cpf != 0)
    {
        int userSetted = 0;

        printf("Digite o seu cpf: ");
        scanf("%ld", &cpf);

        if (cpf == 0)
        {
            break;
        }
        else if (cpf == -1)
        {
            for (i = 0; i < MAX_CHAIRS; i++)
            {
                if (chairs[i] == 0)
                {
                    printf("Assento %d está vazio.\n", i + 1);
                }
            }
        }
        else if (cpf == -2)
        {
            printf("Digite o cpf do usuário que deseja cancelar a passagem: ");
            scanf("%ld", &cpf);

            for (i = 0; i < MAX_CHAIRS; i++)
            {
                if (chairs[i] == cpf)
                {
                    chairs[i] = 0;
                    printf("Passagem cancelada.\n");
                }
            }
        }
        else
        {
            for (i = 0; i < MAX_CHAIRS; i++)
            {
                if ((i % 2 == 0) && (chairs[i] == 0))
                {
                    chairs[i] = cpf;
                    printf("%ld -- Assento #%d (Janela).\n", cpf, i + 1);
                    userSetted = 1;
                    break;
                }
            }
            for (i = 0; i < MAX_CHAIRS; i++)
            {
                if ((i % 2 != 0) && (chairs[i] == 0) && (userSetted == 0))
                {
                    chairs[i] = cpf;
                    printf("%ld -- Assento #%d (Corredor).\n", cpf, i + 1);
                    userSetted = 1;
                    break;
                }
            }

            if (userSetted == 0)
            {
                printf("Todos os assentos estão ocupados.\n");
            }
        }
    }

    return 0;
}
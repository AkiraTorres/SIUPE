#include <stdio.h>
#include <stdlib.h>

void printTable(int tab[3][3]);
void resetTable();

int validateInputPlayer();
void insertPlayerInputInTable(char player, int x, int y, int *tab[3][3]);
int checkWinConditions(int tab[3][3]);
int winner(char player)
{
    char play = ' ';
    printf("Parabéns jogador %c, você ganhou!\nVocês desejam jogar novamente?[S/N] ", player);

    scanf(" %c", &play);
    if (play == 'S')
    {
        return 1;
    }
    return 0;
}

int main()
{
    int k, i, j, tab[3][3] = {{0, 0, 1}, {-1, 1, 0}, {0, 0, 0}}, coords[2] = {-1, -1};

    for (k = 0;; k++)
    {
        char player = k % 2 == 0 ? 'X' : 'O';
        printTable(tab);
        printf("Jogador %c, digite as coordenadas desejadas: ", player);
        scanf("%i %i", &coords[1], &coords[0]);
        tab[coords[0] - 1][coords[1] - 1] = player == 'X' ? 1 : -1;
        // insertPlayerInputInTable(player, coords[0], coords[1], tab);

        if (checkWinConditions(tab))
        {
            if (winner(player))
            {
                // resetTable();
                system("clear");
            }
            else
            {
                break;
            }
        }
    }
    printf("Até depois!\n");
    return 0;
}

void printTable(int tab[3][3])
{
    int i, j;
    char place;

    printf("0 1 2 3\n-------\n");
    for (i = 0; i < 3; i++)
    {
        printf("%i|", i + 1);
        for (j = 0; j < 3; j++)
        {
            if (tab[i][j] == 1)
            {
                place = 'X';
            }
            else if (tab[i][j] == -1)
            {
                place = 'O';
            }
            else
            {
                place = ' ';
            }
            printf("%c ", place);
        }
        printf("\n");
    }
}

void insertPlayerInputInTable(char player, int x, int y, int *tab[3][3])
{
    *tab[x][y] = player == 'X' ? 1 : -1;
}

int checkWinConditions(int tab[3][3])
{
    int i, j;
    if ((tab[0][0] == tab[1][1]) && (tab[1][1] == tab[2][2]) && (tab[1][1] != 0))
    {
        return 1;
    }
    else if ((tab[0][2] == tab[1][1]) && (tab[1][1] == tab[2][0]) && (tab[1][1] != 0))
    {
        return 1;
    }

    for (i = 0; i < 3; i++)
    {
        if ((tab[i][0] == tab[i][1]) && (tab[i][0] == tab[i][2]) && (tab[i][0] != 0))
        {
            return 1;
        }
    }

    for (j = 0; j < 3; j++)
    {
        if ((tab[0][j] == tab[1][j]) && (tab[0][j] == tab[2][j]) && (tab[0][j] != 0))
        {
            return 1;
        }
    }

    return 0;
}
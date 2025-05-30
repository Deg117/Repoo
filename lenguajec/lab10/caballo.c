#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define MOVS 8

int tablero[SIZE][SIZE];
int accesibilidad[SIZE][SIZE] = {
    {2, 3, 4, 4, 4, 4, 3, 2},
    {3, 4, 6, 6, 6, 6, 4, 3},
    {4, 6, 8, 8, 8, 8, 6, 4},
    {4, 6, 8, 8, 8, 8, 6, 4},
    {4, 6, 8, 8, 8, 8, 6, 4},
    {4, 6, 8, 8, 8, 8, 6, 4},
    {3, 4, 6, 6, 6, 6, 4, 3},
    {2, 3, 4, 4, 4, 4, 3, 2}};

int dx[MOVS] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[MOVS] = {1, 2, 2, 1, -1, -2, -2, -1};

int valido(int x, int y)
{
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && tablero[x][y] == -1);
}

int contar_accesibilidad(int x, int y)
{
    int count = 0;
    for (int i = 0; i < MOVS; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (valido(nx, ny))
            count++;
    }
    return count;
}

int main()
{
    srand(time(NULL));
    int x = rand() % SIZE;
    int y = rand() % SIZE;

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            tablero[i][j] = -1;

    tablero[x][y] = 1;

    for (int paso = 2; paso <= SIZE * SIZE; paso++)
    {
        int minAcc = 9, nx = -1, ny = -1;

        for (int i = 0; i < MOVS; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (valido(tx, ty))
            {
                int acc = contar_accesibilidad(tx, ty);
                if (acc < minAcc)
                {
                    minAcc = acc;
                    nx = tx;
                    ny = ty;
                }
            }
        }

        if (nx == -1)
            break; // no hay más movimientos válidos
        x = nx;
        y = ny;
        tablero[x][y] = paso;
    }

    printf("Tablero del recorrido del caballo:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%2d ", tablero[i][j]);
        printf("\n");
    }

    return 0;
}

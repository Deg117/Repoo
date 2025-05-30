#include <stdio.h>

int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int vertical[8] = {1, 2, 2, 1, -1, -2, -2, -1}; // Posibles movimientos del caballo (x, y)
void imprimirtablero(int tablero[8][8]);
int valido(int x, int y, int tablero[8][8]);
int resolver(int x, int y, int movimiento, int tablero[8][8]);
int main()
{
    int tablero[8][8] = {0};

    int filaInicial = 0;
    int columnaInicial = 0;

    tablero[filaInicial][columnaInicial] = 1; // movimiento 1

    if (resolver(filaInicial, columnaInicial, 1, tablero))
    {
        imprimirtablero(tablero);
    }
    else
    {
        printf("No se encontro un recorrido completo.\n");
    }

    return 0;
}

int valido(int x, int y, int tablero[8][8]) // revisa si esta dentro y no se piso aun
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8 && tablero[x][y] == 0);
}

int resolver(int x, int y, int movimiento, int tablero[8][8])
{
    if (movimiento == 8 * 8)
        return 1;

    for (int i = 0; i < 8; i++)
    {
        int sigX = x + horizontal[i];
        int sigY = y + vertical[i];

        if (valido(sigX, sigY, tablero))
        {
            tablero[sigX][sigY] = movimiento + 1;

            if (resolver(sigX, sigY, movimiento + 1, tablero))
            {
                return 1;
            }
            else
            {
                tablero[sigX][sigY] = 0;
            }
        }
    }

    return 0; // No hay movimientos vlidos
}

void imprimirtablero(int tablero[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            printf("%2d ", tablero[i][j]);
        printf("\n");
    }
}

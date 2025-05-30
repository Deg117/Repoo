#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define JUEGOS 1000

int lanzarDados()
{
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

int main()
{
    int gana[22] = {0}, pierde[22] = {0};
    int totalGanados = 0, totalPerdidos = 0;
    int suma, punto, tiros, totalTiros = 0;

    srand(time(NULL));

    for (int juego = 0; juego < JUEGOS; juego++)
    {
        tiros = 1;
        suma = lanzarDados();

        if (suma == 7 || suma == 11)
        {
            gana[1]++;
            totalGanados++;
        }
        else if (suma == 2 || suma == 3 || suma == 12)
        {
            pierde[1]++;
            totalPerdidos++;
        }
        else
        {
            punto = suma;
            while (1)
            {
                suma = lanzarDados();
                tiros++;
                if (suma == punto)
                {
                    gana[tiros > 20 ? 21 : tiros]++;
                    totalGanados++;
                    break;
                }
                else if (suma == 7)
                {
                    pierde[tiros > 20 ? 21 : tiros]++;
                    totalPerdidos++;
                    break;
                }
            }
        }
        totalTiros += tiros;
    }

    printf("Ganados por numero de tiradas:\n");
    for (int i = 1; i <= 21; i++)
    {
        if (i == 21)
            printf(">20:\t%d\n", gana[i]);
        else
            printf("%d:\t%d\n", i, gana[i]);
    }

    printf("\nPerdidos por numero de tiradas:\n");
    for (int i = 1; i <= 21; i++)
    {
        if (i == 21)
            printf("20:\t%d\n", pierde[i]);
        else
            printf("%d:\t%d\n", i, pierde[i]);
    }

    printf("\nProbabilidad de ganar: %.2f%%\n", (totalGanados / (float)JUEGOS) * 100.0);
    printf("Duracion promedio de un juego: %.2f tiradas\n", totalTiros / (float)JUEGOS);

    return 0;
}

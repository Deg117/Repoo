// Brian de Jesus Gastelum Fierro mat:373408
// Generación de Números Aleatorios
// 20-feb-2025
// BGF_ACT4.CPP
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void numeros()
{
    int pares = 0, impares = 0;
    srand(time(NULL));

    printf("Numeros generados\n");
    for (int i = 0; i < 25; i++)
    {
        int num = rand() % 41 + 10;
        if (num % 2 == 0)
        {
            printf("%d - par\n", num);
            pares++;
        }
        else
        {
            printf("%d - impar\n", num);
            impares++;
        }
    }

    printf("Cantidad par: %d\n", pares);
    printf("Cantidad impar: %d\n", impares);
}

int main()
{
    numeros();
    return 0;
}
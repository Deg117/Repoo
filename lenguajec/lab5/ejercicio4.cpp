#include <stdio.h>

int main()
{
    int tam=9, i, j, espacio;
    // Parte de arriba
    for (i = 1; i <= tam; i += 2)
    {
        for (espacio = (tam - i) / 2; espacio > 0; espacio--)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Parte de abajo
    for (i = tam - 2; i > 0; i -= 2)
    {
        for (espacio = (tam - i) / 2; espacio > 0; espacio--)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

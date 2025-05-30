#include <stdio.h>

int main()
{
    int medida, i, j;
    printf("Dame el tamaño del cuadro para imprimirlo (1-20)\n-1 Para finalizar\n");
    scanf("%d", &medida);
    while (medida != -1)
    {
        for (i = 0; i < medida; i++)
        {
            for (j = 0; j < medida; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        printf("Dame el tamaño del cuadro para imprimirlo (1-20)\n -1 Para finalizar\n");
        scanf("%d", &medida);
    }
    return 0;
}
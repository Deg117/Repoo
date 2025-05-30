#include <stdio.h>

int main()
{
    int medida, i, j;
    printf("Dame el tamaño del cuadro para imprimir el perímetro (1-20)\n-1 Para finalizar\n");
    scanf("%d", &medida);
    while (medida != -1)
    {
        for (i = 0; i < medida; i++)
        {
            for (j = 0; j < medida; j++)
            {
                if (i == 0)
                {
                    printf("*"); // Primera fila
                }
                else if (i == medida - 1)
                {
                    printf("*"); // Última fila
                }
                else
                {
                    if (j == 0)
                    {
                        printf("*"); 
                    }
                    else if (j == medida - 1)
                    {
                        printf("*"); 
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
        printf("Dame el tamaño del cuadro para imprimir el perímetro (1-20)\n-1 Para finalizar\n");
        scanf("%d", &medida);
    }
    return 0;
}

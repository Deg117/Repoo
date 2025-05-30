#include <stdio.h>
int main()
{
    int j = 0, i, k = 0,tam;
    printf("Dame la medida del tiangulo");
    scanf("%d",&tam);
    tam++;
    for (i = 1; i < tam; i++)
    {
        for (j = (tam - i); j < tam; j++)
        {
            printf("*");
        }
        for (j = 0; j < (tam - i); j++)
        {
            printf(" ");
        }

        for (j = 0; j < (tam - i); j++)
        {
            printf("*");
        }
        for (j = (tam - i); j < tam; j++)
        {
            printf(" ");
        }
        for (j = (tam - i); j < tam; j++)
        {
            printf(" ");
        }
        for (j = 0; j < (tam - i); j++)
        {
            printf("*");
        }

        for (j = 0; j < (tam - i); j++)
        {
            printf(" ");
        }
        for (j = (tam - i); j < tam; j++)
        {
            printf("*");
        }
      
       printf("\n");
    
    
    }

    return 0;
}
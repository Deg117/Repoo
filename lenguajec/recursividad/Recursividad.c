/*
Gastelum Fierro Brian de jesus
373408
Recursividad
11/04/2025
*/
#include <stdio.h>
int suma(int n);
int main()
{
    int enteropositivo = 0;
    printf("Ingresar un n%cmero entero para obtener la sumatoria:\n ", 163);
    scanf("%d", &enteropositivo);

    printf("La sumatoria de %d es :\n ", enteropositivo);
    printf("%d", suma(enteropositivo));
}

int suma(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        if(n>1)
        {
            printf("%2d +",n);
        }
       // printf("%2d +", n);
        return n + suma(n - 1);
    }
}
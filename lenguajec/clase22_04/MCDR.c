
#include <stdio.h>

int suma(int a);

int main()
{
    int a, resultado;
    printf("Ingresa un numero entero para obtener la sumatoria\n");
    scanf("%d", &a);
    resultado = suma(a);
    printf("0\n");
    printf("Resultado de la suma: %d\n", resultado);
    return 0;
}

int suma(int a)
{ 
    if (a <= 0)
    {
        printf("suma(0) = 0\n");
        return 0;
    }
    else
    {
        printf("%d + suma(%d)\n", a, a - 1);
        printf("|\n");
        printf("|\n");
        printf("%c\n", 25);  
        return a + suma(a - 1);
    }
}
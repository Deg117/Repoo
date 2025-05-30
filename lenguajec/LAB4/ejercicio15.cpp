#include <stdio.h>

int main()
{
    int numdeci, residuo;
    int i = 0;

    printf("Ingresa un numero entero positivo: ");
    scanf("%d", &numdeci);
    if (numdeci == 0)
    {
        printf("El numero en binario es: 0\n");
        return 0;
    }
    printf("El numero en binario es: ");
    while (numdeci > 0)
    {
        residuo = numdeci % 2;
        printf("%d", residuo);
        numdeci = numdeci / 2;
    }
    printf("\n");
    return 0;
}

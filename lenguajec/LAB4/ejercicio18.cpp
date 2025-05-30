#include <stdio.h>

int main()
{
    int num, i = 0;
    printf("Ingresa un numero entero: ");
    scanf("%d", &num);
    while (num != 0)
    {
        if (num % 10 == 7)
        {
            i++;
        }
        num = num / 10;
    }
    printf("El numero de 7 es: %d\n", i);
    return 0;
}

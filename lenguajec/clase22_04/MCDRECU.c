#include <stdio.h>

int max_comun_divisor(int a, int b); 

int main()
{
    int a, b, c;
    printf("Introduzca dos enteros positivos para mostrar el MCD:\n");
    scanf("%d", &a);
    scanf("%d", &b);

    c = max_comun_divisor(a, b);
    printf("El MCD de %d y %d es: %d\n", a, b, c);

    return 0;
}

int max_comun_divisor(int a, int b)
{
    if (b == 0)
        return a;
    else
        return max_comun_divisor(b, a % b);
}
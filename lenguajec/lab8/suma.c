#include <stdio.h>

int suma(int n);
int main()
{
    int n;
    printf("Ingrese un numero entero: ");
    scanf("%d", &n);

    printf("Ejemplo ilustrativo de la sumatoria recursiva:\n");
    printf("%d + suma(%d)\n", n, n - 1);
    int resultado = suma(n);
    printf("= %d\n", resultado);

    return 0;
}
int suma(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        printf("%d + suma(%d)\n", n, n - 1);
        return n + suma(n - 1);
    }
}

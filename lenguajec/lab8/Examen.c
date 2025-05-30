#include <stdio.h>

int mcd(int a, int b)
{
    if (b == 0)
        return a;
    return mcd(b, a % b);
}

int contarDigitos(int n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

void mostrarPasosMCD(int a, int b, int nivel)
{
    for (int i = 0; i < nivel * 4; i++)
        printf(" ");

    printf("mcd(%d, %d mod %d)\n", b, a, b);

    int offset = nivel * 4 + 4 + contarDigitos(b) + 2;

    for (int i = 0; i < offset; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < offset; i++)
        printf(" ");
    printf("V\n");

    if (a % b != 0)
    {
        mostrarPasosMCD(b, a % b, nivel + 1);
    }
    else
    {
        for (int i = 0; i < (nivel + 1) * 4; i++)
            printf(" ");
        printf("mcd(0, %d mod 0)\n", b);
    }
}

void imprimirMCDConFormato(int a, int b)
{
    printf("mcd(%d, %d)\n", a, b);

    int offset = 4; // Solo la longitud de "mcd("
    for (int i = 0; i < offset; i++)
        printf(" ");
    printf("|\n");
    for (int i = 0; i < offset; i++)
        printf(" ");
    printf("V\n");

    mostrarPasosMCD(a, b, 1);

    int resultado = mcd(a, b);
    printf("\nResultado: MCD(%d, %d) = %d\n", a, b, resultado);
}

int main()
{
    int a, b;
    printf("Introduzca los dos enteros positivos para mostrar el MCD:\n");
    scanf("%d %d", &a, &b);
    imprimirMCDConFormato(a, b);
    return 0;
}

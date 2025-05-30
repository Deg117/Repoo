#include <stdio.h>
//Brian de jesus Gastelum Fierro

int mcd(int a, int b, int nivel);

int main()
{
    int num1, num2,resultado;
    printf("Introduce dos enteros positivos para mostrar el MCD:\n");
    scanf("%d %d", &num1, &num2);

    resultado = mcd(num1, num2, 0);

    return 0;
}

int mcd(int a, int b, int nivel)
{
    for (int i = 0; i < nivel; i++)
        printf("    ");

    if (b == 0)
    {
        printf("mcd(%d, %d)\n", a, b);
        return a;
    }
    else
    {
        printf("mcd(%d, %d mod %d)\n", a, b, a);

        for (int i = 0; i <= nivel; i++)
            printf("    ");
        printf("|\n");

        for (int i = 0; i <= nivel; i++)
            printf("    ");
        printf("V\n");

        return mcd(b, a % b, nivel + 1);
    }
}

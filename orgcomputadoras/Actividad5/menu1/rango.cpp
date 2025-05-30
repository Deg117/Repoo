#include <stdio.h>

void validarRango(void)
{
    int numero;

    do
    {
        scanf("%d", &numero);

        if (numero < 1 || numero > 100)
        {
            printf("Error: El numero debe estar entre 1 y 100. Intenta de nuevo.\n");
        }
    } while (numero < 1 || numero > 100);

    printf("El numero ingresado es %d, y es valido.\n", numero);
}

int main()
{
    validarRango();
    return 0;
}

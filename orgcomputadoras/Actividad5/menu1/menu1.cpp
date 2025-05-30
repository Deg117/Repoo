//  Brian de jesus Gastelum Fierro
//  Matricula:373408
//  Menu
//  28/feb/2025
//  BGF_ACT5_.CPP
#include <stdio.h>

void nrango(void)
{
    int n1, i = 0, sum = 0, j = 0, porcentaje, incorrec;

    printf("Dame un valor entre 10 y 50 ( 0 para finalizar):\n");
    scanf("%d", &n1);

    while (n1 != 0)
    {
        if (n1 >= 10 && n1 <= 50)
        {
            sum = sum + n1;
            j++;
        }
        i++;

        printf("Dame un valor entre 10 y 50 ( 0 para finalizar):\n");
        scanf("%d", &n1);
    }

    if (i > 0)
    {
        porcentaje = (j * 100) / i;
        incorrec = i - j;
        printf("La cantidad de numeros son %d\n", i);
        printf("La suma de numeros correctos son %d\n", sum);
        printf("La cantidad de numeros incorrectos son %d\n", incorrec);
        printf("Porcentaje de numeros correctos: %d%%\n", porcentaje);
    }
    else
    {
        printf("No se ingreso algun numero validos.\n");
    }
}

void validarRango(void)
{
    int numero;
    printf("Dame un numero  entre 1 y 100\n");
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
void digitos(void)
{
    int num, i = 0;
    printf("Dame un numero entero y te dire cuantos digitos tiene\n");
    scanf("%d", &num);

    do
    {
        num = num / 10;
        i++;
    } while (num != 0);

    printf("Tiene %d digitos\n", i);
}
int main()
{
    int opcion;
    do
    {
        printf(" Menu\n");
        printf("1. Lectura de numeros en un rango (10-50)\n");
        printf("2. Validacion de entrada de un rango (1-100)\n");
        printf("3. Contar digitos de un numero\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: \n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            nrango();
            break;
        case 2:
            validarRango();
            break;
        case 3:
            digitos();
            break;
        default:
            printf("saliendo\n");
        }

    } while (opcion != 4);

    return 0;
}
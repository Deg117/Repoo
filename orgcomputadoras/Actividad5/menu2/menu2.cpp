//  Brian de jesus Gastelum Fierro
//  Matricula:373408
//  Menu
//  01/03/2025
//  BGF_ACT5_.CPP
#include <stdio.h>

void promedio(void)
{
    int calif, suma = 0;
    float intento = 1, prom;

    while (intento <= 3)
    {
        printf("Ingrese la calificacion del intento %.1f(0-100): ", intento);
        scanf("%d", &calif);
        if (calif < 0 || calif > 100)
        {
            printf("La calificacion debe estar entre 0 y 100.\n");
        }
        suma += calif;
        if (calif >= 60)
        {
            prom = suma / intento;
            printf("Felicidades estas en el siguiente semestre tu promedio es: %.2f\n", prom);
            return;
        }
        else
        {
            printf("Reprobaste en este intento.\n");
        }

        intento++;
    }

    printf("Baja Academica\n");
}

void tablas()
{
    int num = 1, i;
    printf("\n Tablas de Multiplicar del 1 al 10\n");
    while (num <= 10)
    {
        printf("\nTabla del %d:\n", num);
        i = 1;
        while (i <= 10)
        {
            printf("%d x %d = %d\n", num, i, num * i);
            i++;
        }
        num++;
    }
}

void digitos()
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
void facto(void)
{
    int num, facto = 1, i;
    do
    {
        printf("Dame un numero entre 1 y 10:");
        scanf("%d", &num);
        if (num < 1 || num > 10)
        {
            printf("Numero fuera de rango\n");
        }
    } while (num < 1 || num > 10);
    i = num;
    while (i > 1)
    {
        facto = facto * i;
        i--;
    }

    printf("Factorial es %d\n", facto);
}

int main()
{
    int opcion;
    do
    {
        printf(" Menu\n");
        printf("1.Calcular promedio de una materia\n");
        printf("2.Imprimir tablas de multiplicar.\n");
        printf("3. Contar digitos de un numero.\n");
        printf("4. Calcular factorial.\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: \n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            promedio();
            break;
        case 2:
            tablas();
            break;
        case 3:
            digitos();
            break;
        case 4:
            facto();
            break;
        default:
            printf("saliendo\n");
        }

    } while (opcion != 5);

    return 0;
}
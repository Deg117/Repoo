// Brian de Jesus Gastelum Fierro mat:373408
// Menú Interactivo
// 22-feb-2025
// BGF_ACT4.CPP
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void del1_al_10()
{
    int i, sum = 0;
    for (i = 1; i <= 10; i++)
    {
        sum += i;
        printf("%d\n", i);
    }
    printf("La suma de los 10 numeros es %d\n", sum);
}

void menores(int n)
{
    int sum = 0, prom, i;
    printf("Numeros menores a n en orden descendente:\n");
    for (i = n - 1; i > 0; i--)
    {
        printf("%d\n", i);
        sum += i;
    }
    prom = sum / n;
    printf("Suma: %d\n", sum);
    printf("Promedio: %d\n", prom);
}
#define N 20
void promedio()
{
    float sum = 0, n;
    for (int i = 1; i <= N; i++)
    {
        printf("Dame 20 numeros y te mostrare la suma y su promedio");
        scanf("%f", &n);
        sum = sum + n;
    }
    printf("La suma total es %.2f\n", sum);
    printf("El promedio es %.2f\n", sum / N);
}

void tabla_multiplicar(int num)
{
    printf("Tabla de multiplicar del %d:\n", num);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", num, i, num * i);
    }
}

void ramdon()
{
    int pares = 0, impares = 0;
    srand(time(NULL));

    printf("Numeros generados:\n");
    for (int i = 0; i < 25; i++)
    {
        int num = rand() % 41 + 10;
        if (num % 2 == 0)
        {
            printf("%d - par\n", num);
            pares++;
        }
        else
        {
            printf("%d - impar\n", num);
            impares++;
        }
    }
    printf("Cantidad de pares: %d\n", pares);
    printf("Cantidad de impares: %d\n", impares);
}

void menu()
{
    int opcion, n;
    do
    {
        printf("\nMenu:\n");
        printf("1.numeros del 1 al 10 y su suma.\n");
        printf("2.numeros menores a n, suma y promedio.\n");
        printf("3.suma y promedio de 20 numeros.\n");
        printf("4.tabla de multiplicar.\n");
        printf("5.numeros aleatorios.\n");
        printf("6.Salir.\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            del1_al_10();
            break;
        case 2:
            printf("Ingrese un numero mayor a 1: ");
            scanf("%d", &n);
            if (n > 1)
            {
                menores(n);
            }
            else
            {
                printf("El numero debe ser mayor a 1.\n");
            }
            break;
        case 3:
            promedio();
            break;
        case 4:
            printf("Ingresa un numero para la tabla: ");
            scanf("%d", &n);
            tabla_multiplicar(n);
            break;
        case 5:
            ramdon();
            break;
        case 6:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida\n");
        }
    } while (opcion != 6);
}

int main()
{
    menu();
    return 0;
}

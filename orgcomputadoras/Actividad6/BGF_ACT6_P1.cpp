/*Brian De Jesus Gatelum Fierro
Matricula:373408
Menu
03/03/2025-05/03/2025-07/03/2025-08/03/2025
BGF_ACT6_PE_.CPP
*/
#include "brian.h"
void facto();
void numaleatorios();
void califalgebra();
void derechoexam();
void sueldocomision();
void tablas();

int main() // listo
{
    int op;
    do
    {
        printf("Menu\n");
        printf("1. Calcular el factorial de un numero\n");
        printf("2. Generar numeros aleatorios\n");
        printf("3. Evaluar calificaciones algebra\n");
        printf("4. Derecho a examen de nivelacion\n");
        printf("5. Calcular sueldo y comisiones\n");
        printf("6. Imprimir tabalas de multiplicar\n");
        printf("0. Salir\n");
        op= validar(0,6,"Escoje una opcion: \n");
        switch (op)
        {
        case 1:
            facto();
            break;
        case 2:
            numaleatorios();
            break;
        case 3:
            califalgebra();
            break;
        case 4:
            derechoexam();
            break;
        case 5:
            sueldocomision();
            break;
        case 6:
            tablas();
            break;
        }

    } while (op != 0);
}

void facto(void) // listo
{
    int num, facto = 1, i;
    do
    {
        num=validar (0,15,"Dame un numero entre \n");
    } while (num < 0 || num > 15);
    i = num;
    while (i > 0)
    {
        facto *= i;
        i--;
    }

    printf("Factorial es %d\n", facto);
}

void numaleatorios(void) // listo
{
    int pares = 0, impares = 0;
    float mediapar, sumpar = 0;
    srand(time(NULL));

    printf("Numeros generados\n");
    for (int i = 0; i < 25 && pares < 13; i++)
    {
        int num = rand() % 101 + 100;
        if (num % 2 == 0)
        {
            printf("%d - par\n", num);
            pares++;
            sumpar += num;
        }
        else
        {
            printf("%d - impar\n", num);
            impares++;
        }
        if (pares > 0)
        {
            mediapar = sumpar / pares;
        }
        else
        {
            mediapar = 0;
        }
    }
    printf("Media de numeros par: %.2f\n", mediapar);
    printf("Cantidad par: %d\n", pares);
    printf("Cantidad impar: %d\n", impares);
}

void califalgebra(void) // listo
{
    float calif, suma = 0, prom;
    int fallos = 0, aprobado = 0;

    while (fallos < 3)
    {
        calif=validar(0,100,"Dame tu calificacion\n");
        if (calif >= 60)
        {
            suma += calif;
            aprobado++;
            break; // sin el no dejaba de pedir calificaciones
        }
        else
        {
            fallos++;
        }
    }
    if (aprobado > 0)
    {
        prom = suma / aprobado;
    }
    else
    {
        prom = 0;
    }

    if (prom >= 60)
    {
        printf("Aprobaste promedio de: %.2f\n", prom);
    }
    else
    {
        printf("Numero de fallos alcanzados baja academica.\n");
        printf("El promedio es %.2f\n", prom);
    }
}
void derechoexam(void) // listo
{
    int alumnos = 40, sinderecho = 0, calif;
    float prom;
    for (int i = 1; i <= alumnos; i++)
    {
        float suma = 0;
        printf("Dame las 5 calificaciones del alumno %d\n",i);
        for (int j = 1; j < 5; j++)
        {
            calif=validar(0,100,"Dame la Calificacion \n");
            suma += calif;
        }
        prom = suma / 5;
        printf("El promedio de este alumno es %.2f\n", prom);
        if (prom < 50)
        {
            sinderecho++;
        }
    }

    printf("Los alumnos sin derecho a examen son %d\n", sinderecho);
}

void sueldocomision(void) // listo
{
    float sueldoBase, ventas, totalComisiones = 0, sueldoTotal;
    int semanas;
    sueldoBase=validar(0,3000,"Dame El sueldo base del vendedor\n");

    semanas=validar(0,10,"Dame las semanas trabajadas\n");
    for (int i = 1; i <= semanas; i++)
    {
        ventas=validar(0,3000,"DAme las venstas de la semana\n");
             totalComisiones += ventas * 0.10;
    }
    sueldoTotal = sueldoBase + totalComisiones;
    printf("Sueldo base: %.2f\n", sueldoBase);
    printf("Total de comisiones: %.2f\n", totalComisiones);
    printf("Sueldo total del vendedor: %.2f\n", sueldoTotal);
}
void tablas(void) // listo
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
        printf("\npresione enter para continuar");
        fflush(stdin);
        getchar();
        num++;
    }
}

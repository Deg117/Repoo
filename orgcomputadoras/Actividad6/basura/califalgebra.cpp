#include <stdio.h>

void califalgrebra(void)
{
    float calif, suma = 0, prom;
    int fallos = 0, aprobado = 0;

    while (fallos  <3)
    {
        printf("Dame tu calificacion: ");
        scanf("%f", &calif);

        if (calif >= 60)
        {
            suma += calif;
            aprobado++;
            break;              //sin el no dejaba de pedir calificaciones
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
int main()
{
    califalgrebra();
    return 0;
}

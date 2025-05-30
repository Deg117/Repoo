#include <stdio.h>

void Promedio()
{
    int calif, suma = 0;
    float intento = 1, prom;

    while (intento <= 3)
    {
        printf("Ingrese la calificacion del intento %f(0-100): ", intento);
        scanf("%d", &calif);

        if (calif < 0 || calif > 100)
        {
            printf("La calificacion debe estar entre 0 y 100.\n");
        }
        suma += calif;
        if (calif >= 60)
        {
            prom = suma / intento;
            printf("Felicidades, estas en el siguiente semestre tu promedio es: %.2f\n", prom);
            return;
        }
        else
        {
            printf("Reprobaste en este intento.\n");
        }

        intento++;
    }

    printf("Baja Academica reprobaste 3 veces.\n");
}
int main()
{
    Promedio();
    return 0;
}
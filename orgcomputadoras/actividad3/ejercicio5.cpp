// Brian de Jesus Gastelum Fierro mat:373408
// Sistema de Evaluación de Calificacion
// 14-feb-2025
// BGF_ACT3.CPP
#include <stdio.h>

int main()
{
    float cal1, cal2, cal3, prom;
    printf("Dame tu primer calificacion\n");
    scanf("%f", &cal1);
    printf("Dame tu segunda calificacion\n");
    scanf("%f", &cal2);
    printf("Dame tu tercer calificacion\n");
    scanf("%f", &cal3);
    prom = (cal1 + cal2 + cal3) / 3;
    printf("Tu promedio es %f\n", prom);
    if (prom > 100)
    {
        printf("Error en promedio\n");
    }
    else if (prom >= 98)
    {
        printf("Excelente\n");
    }
    else if (prom >= 90)
    {
        printf("MUY bien\n");
    }
    else if (prom >= 80)
    {
        printf("Bien\n");
    }
    else if (prom >= 70)
    {
        printf("Regular\n");
    }
    else if (prom >= 60)
    {
        printf("suficiente\n");
    }
    else if (prom >= 30)
    {
        printf("Extraordinario\n");
    }
   
    return 0;
}

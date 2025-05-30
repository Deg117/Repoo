// Brian de Jesus Gastelum Fierro mat:373408
// Promedio Final con Examen Anulado
// 6-feb-2025
// BGF_ACT3.CPP
#include <stdio.h>

int main()
{
    float calif1, calif2, calif3, calif4, calif5;
    float suma = 0, promedio, menor;

    printf("Ingrese la calificación 1: ");
    scanf("%f", &calif1);

    printf("Ingrese la calificación 2: ");
    scanf("%f", &calif2);

    printf("Ingrese la calificación 3: ");
    scanf("%f", &calif3);

    printf("Ingrese la calificación 4: ");
    scanf("%f", &calif4);

    printf("Ingrese la calificación 5: ");
    scanf("%f", &calif5);

    menor = calif1;
    if (calif2 < menor)
        menor = calif2;
    if (calif3 < menor)
        menor = calif3;
    if (calif4 < menor)
        menor = calif4;
    if (calif5 < menor)
        menor = calif5;

    if (calif1 != menor)
        suma = calif1;
    if (calif2 != menor)
        suma = suma + calif2;
    if (calif3 != menor)
        suma = suma + calif3;
    if (calif4 != menor)
        suma = suma + calif4;
    if (calif5 != menor)
        suma = suma + calif5;

    promedio = suma / 4;

    printf("El promedio final es: %.2f\n", promedio);

    return 0;
}

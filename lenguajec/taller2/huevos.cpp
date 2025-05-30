#include <stdio.h>

int main()
{
    int huevos, carteras_completas, huevos_ultima, huevos_faltantes;

    printf("Ingrese la cantidad de huevos: ");
    scanf("%d", &huevos);

    carteras_completas = huevos / 6;
    huevos_ultima = huevos - (carteras_completas * 6);
    huevos_faltantes = 6 - huevos_ultima;

    if (huevos_ultima == 6)
    {
        huevos_ultima = 0;
        huevos_faltantes = 0;
    }

    printf("Cantidad de huevos ingresados: %d\n", huevos);
    printf("Carteras llenas con 6 huevos: %d\n", carteras_completas);
    printf("Huevos en la ultima cartera: %d\n", huevos_ultima);
    printf("Huevos faltantes en la ultima cartera: %d\n", huevos_faltantes);

    return 0;
}
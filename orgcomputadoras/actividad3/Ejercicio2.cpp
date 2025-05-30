// Brian de Jesus Gastelum Fierro Mat.373408
// Conversion de unidades
// 11/Feb/2025
// BGF_ACT3_.CPP
#include <stdio.h>
int main()
{
    float n1;
    int op;
    int cenapul = 1;
    int cenapies = 2;
    int klami = 3;
    int pulacen = 4;
    int piesacen = 5;
    int miakil = 6;
    printf("Dame una opcion del menu\n");
    printf("Menu\n");
    printf("1.Centimetros a pulgadas\n");
    printf("2.centimetros a pies\n");
    printf("3.Kilometros a millas\n");
    printf("4.Pulgadas a centimetros\n");
    printf("5.Pies a centimetros\n");
    printf("6.Millas a Kilometros\n");
    printf("Opcion\n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        printf("Introduce la cantidad a convertir: ");
        scanf("%f", &n1);
        printf("1 pulgada=2.54cm\n");
        cenapul = n1 / 2.54;
        printf("La conversion de centimetros a pulgadas es: %.2d\n", cenapul);
        break;
    case 2:
        printf("Introduce la cantidad a convertir: ");
        scanf("%f", &n1);
        printf("1 pie=30.48 cm\n");
        cenapies = n1 / 30.48;
        printf("La conversion de centimetros a pies es: %.2d\n", cenapies);
        break;
    case 3:
        printf("Introduce la cantidad a convertir: ");
        scanf("%f", &n1);
        printf("1 Milla= 1.609kilometros\n");
        klami = n1 * 0.621;
        printf("La conversion de kilometros a millas es: %.2d\n", klami);
        break;
    case 4:
        printf("Introduce la cantidad a convertir: ");
        scanf("%f", &n1);
        printf("2.54cm=1 pulgada\n");
        pulacen = n1 * 2.54;
        printf("La conversion de pulgadas a centimetros es: %.2d\n", pulacen);
        break;
    case 5:
        printf("Introduce la cantidad a convertir: ");
        scanf("%f", &n1);
        printf("1 pie= 30.48 cm\n");
        piesacen = n1 / 30.48;
        printf("La conversion de pies a centimetros: %.2d\n", piesacen);
        break;
    case 6:
        printf("Introduce la cantidad a convertir: ");
        scanf("%f", &n1);
        printf("1 kilometro= 0.621 millas\n");
        miakil = n1 * 1.609;
        printf("La conversion de millas a kilometros es: %.2d\n", miakil);
        break;

    default:
        printf("Opcion no valida");
    }
    return 0;
}

// Brian de Jesus Gastelum Fierro mat.373408
// Calculadora
// 11/Feb/2025
// BGF_ACT3_.CPP
#include <stdio.h>
int main()
{
    int sum = 1;
    int rest = 2;
    int multi = 3;
    int div = 4;
    int op, n1, n2;
    printf("Menu");
    printf("Dame una opcion del menu.\n1.Suma\n2.Resta\n3.Multiplicacion\n4.Division\n");
    printf("Opcion\n");
    scanf("%d",&op);
    printf("Dame dos numeros\n");
    scanf("%d", &n1);
    scanf("%d", &n2);

    switch (op)
    {
    case 1:
        sum = n1 + n2;
        printf("El resultado de la suma es: %.2d\n", sum);
        break;
    case 2:
        rest = n1 - n2;
        printf("El resultado de la resta es: %.2d\n", rest);

        break;
    case 3:
        multi = n1 * n2;
        printf("El resultado de la Multiplicacion es: %.2d\n", multi);
        break;
    case 4:
        div = n1 / n2;
        printf("El resultado de la Division es: %.2d\n", div);
    default:
        printf("Opcion no valida Error\n");
    }
    return 0;
}

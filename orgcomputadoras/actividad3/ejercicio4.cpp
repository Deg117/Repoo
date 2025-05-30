// Brian de Jesus Gastelum Fierro mat:373408
// Determinación del Número Medio
// 6-feb-2025  modificacion 14/feb/2025
// BGF_ACT3.CPP
#include <stdio.h>
int main()
{
    int num1, num2, num3;
    printf("Dame 3 numeros y te dire cual es el del medio\n");
    printf("Dame el primer numero\n");
    scanf("%d", &num1);
    printf("Dame el segundo numero\n");
    scanf("%d", &num2);
    printf("Dame el tercer numero\n");
    scanf("%d", &num3);
    if ((num1 > num2 && num1 < num3) || (num1 > num3 && num1 < num2))
    {
        printf("El numero del medio es: %d\n", num1);
    }
    else if ((num2 > num1 && num2 < num3) || (num2 > num3 && num2 < num1))
    {
        printf("El numero del medio es: %d\n", num2);
    }
    else
    {
        printf("El numero del medio es: %d\n", num3);
    }

    return 0;
}

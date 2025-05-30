// Brian de Jesus Gastelum Fierro mat:373408
// Determinación del Número Mayor
// 6-feb-2025
// BGF_ACT3.CPP
#include <stdio.h>
int main()
{
    int num1, num2, num3;
    printf("Dame 3 numeros y te dire cual es el mayor\n");
    printf("Dame el primer numero\n");
    scanf("%d", &num1);
    printf("Dame el segundo numero\n");
    scanf("%d", &num2);
    printf("Dame el tercer numero\n");
    scanf("%d", &num3);
    if (num1 == num2 && num2 == num3)
    {
         printf("Los numeros son iguales %d%d%d\n",num1,num2,num3);
    }
    else if (num1 > num2 && num1 > num3)
    {
        printf("El numero mayor es %d\n", num1);
    }
    else if (num2 > num1 && num2 > num3)
    {
        printf("El numero mayor es %d\n", num2);
    }
    else
    {
        printf("El numero mayor es  %d\n", num3);
    }
    return 0;
}

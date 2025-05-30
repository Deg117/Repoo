#include <stdio.h>

    int main()
{
    float num1, num2, num3;

    printf("Ingrese el primer numero:\n ");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero:\n ");
    scanf("%f", &num2);
    printf("Ingrese el tercer numero:\n ");
    scanf("%f", &num3);

    if (num1 == num2)
    {
        if (num2 == num3)
        {
            printf("Los valores %.2f, %.2f y %.2f son iguales.\n", num1, num2, num3);
        }
    }
    if (num1 != num2)
    {
        printf("Los valores %.2f, %.2f y %.2f no son iguales.\n", num1, num2, num3);
    }
    
    return 0;
}
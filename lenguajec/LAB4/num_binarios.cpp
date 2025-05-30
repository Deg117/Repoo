#include <stdio.h>

int main()
{
    int num, residuo, deci, total, i = 0;
    printf("Ingresa un numero binario y te dare su decimal\n");
    scanf("%d", &num);
    while (deci > 0)
    {
        residuo = num % 10;
        deci = deci +residuo * 2 ;
        total= num/10;
    }
    printf("El numero decimall es %d\n", deci);
    return 0;
}
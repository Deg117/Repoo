#include <stdio.h>
#include <math.h>
int main() 
{
    int num1, num2;
    printf("Dame el primer numero: ");
    scanf("%d", &num1);
    printf("Dame el segundo numero: ");
    scanf("%d", &num2);
    if (num2 != 0 && num1 % num2 == 0) {
        printf("%d es múltiplo de %d.\n", num1, num2);
    }
    if (num2 != 0 && num1 % num2 != 0) {
        printf("%d no es multiplo de %d.\n", num1, num2);
    }

    return 0;
}
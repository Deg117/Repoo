#include <stdio.h>

int main()
{
    int num,num2;
    int div = 2;
    printf("Dame un numero: ");
    scanf("%d", &num);
    if (num > 1)
    {
        num2 = num;
        printf("Factores primos:\n");
        while (num > 1)
        {
            if (num % div == 0)
            {
                printf("%d*",div);
                num /= div;
            }
            else
            {
                div++;
            }
        }
        printf("\b= %d\n",num2);
    }
    else
    {
        printf("Tu numero no tiene factores primos.\n");
    }

    return 0;
}
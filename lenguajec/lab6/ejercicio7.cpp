#include <stdio.h>
int main()
{
    int num;
    for (int i = 0; i < 5; i++)
    {
        printf("Dame un numero\n");
        scanf("%d", &num);
        if (num >= 1 && num <= 99)
        {
            for (int j = 0; j < num; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        else
        {
            printf(" Dame un numero entre 1 y 99.\n");
            i--;
        }
    }
    return 0;
}
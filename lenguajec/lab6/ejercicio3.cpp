#include <stdio.h>

int main()
{
    for (int i = 1; i <= 1; i++)
    {
        for (int j = 1; j <= 1;j++)
        {
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    printf("*");
                }
                printf("\n");
            }

            for (int i = 10; i >= 1; i--)
            {
                for (int j = 1; j <= i; j++)
                {
                    printf("*");
                }
                printf("\n");
            }

            for (int i = 10; i >= 1; i--)
            {
                for (int j = 1; j <= 10 - i; j++)
                {
                    printf(" ");
                }
                for (int j = 1; j <= i; j++)
                {
                    printf("*");
                }
                printf("\n");
            }

            for (int i = 1; i <= 10; i++)
            {
                for (int j = 10; j > i; j--)
                {
                    printf(" ");
                }
                for (int j = 1; j <= i; j++)
                {
                    printf("*");
                }
                printf("\n");
            }
        }
    }
    return 0;
}

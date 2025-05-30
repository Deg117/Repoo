#include <stdio.h>
int main()
{
    int j = 0, i, k = 0;
    for (i = 1; i < 11; i++)
    {
        for (j = (11 - i); j < 11; j++)
        {
            printf("*");
        }
        for (j = 0; j < (11 - i); j++)
        {
            printf(" ");
        }

        for (j = 0; j < (11 - i); j++)
        {
            printf("*");
        }
        for (j = (11 - i); j < 11; j++)
        {
            printf(" ");
        }
        for (j = (11 - i); j < 11; j++)
        {
            printf(" ");
        }
        for (j = 0; j < (11 - i); j++)
        {
            printf("*");
        }

        for (j = 0; j < (11 - i); j++)
        {
            printf(" ");
        }
        for (j = (11 - i); j < 11; j++)
        {
            printf("*");
        }
      
       printf("\n");
    
    }

    return 0;
}
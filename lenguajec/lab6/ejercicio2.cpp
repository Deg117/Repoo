#include <stdio.h>

int main()
{
    int num, i;
    long long facto; 

    printf("Numero | Factorial\n");
    printf("-------|--------------------\n");

    for (num = 0; num <= 20; num++)
    {
        facto = 1; 

        for (i = 1; i <= num; i++)
        {
            facto *= i;
        }

        printf("%5d  | %20lld\n", num, facto); 
    }

    return 0;
}

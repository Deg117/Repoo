#include <stdio.h>

int main()
{
    int a = 2, b = 2,g=6;

    if (!(a==b)||!(g!=5))
    {
        printf("Verdadero");
    }
    if (!(a==b)&& !(g!=5))
    {
        printf("Verdadero");
    }

    return 0;
}

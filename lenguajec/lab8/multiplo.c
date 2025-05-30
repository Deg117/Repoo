#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int multiplo(int a, int b);
int main()
{
    srand(time(NULL));

    for (int i = 0; i < 1000; i++)
    {
        int a = rand() % 1000 + 1;
        int b = rand() % 1000 + 1;

        if (multiplo(a, b))
        {
            printf("%d es un multiplo de %d\n", b, a);
        }
        else
        {
            printf("%d no es un multiplo de %d\n", b, a);
        }
    }

    return 0;
}

int multiplo(int a, int b)
{
    if (b == 0)
    {
        return 0; // no es mltiplo
    }
    if (a % b == 0)
    {
        return 1; //a si es 
    }
    else
    {
        return 0; // a no es
    }
}
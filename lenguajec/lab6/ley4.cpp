#include <stdio.h>

int main()
{
    int i=5, j=7;

    if (!(i>4)||(j<=6))
    {
        printf("Verdadero");
    }
    if (!(i >4) && (j > 6))
    {
        printf("Verdadero");
    }

    return 0;
}

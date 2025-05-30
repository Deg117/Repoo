#include <stdio.h>

int main()
{
    int x = 2, y = 5;

    if (!((x < 8) && !(y > 4)))
    {
        printf("Verdadero");
    }
    if (!(x <= 8) || (y > 4))
    {
        printf("Verdadero");
    }

    return 0;
}

// Gastelum Fierro brian de Jesus

#include <stdio.h>
int main()
{
    int n = -1;
    while (n <= 8)
    {
        n = n + 1;
        if (n <= 8)
        {

            printf("%d,", n);
        }
        if (n == 9)
        {
            printf("y %d.", n);
        }
    }

    return 0;
}
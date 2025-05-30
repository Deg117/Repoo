#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num1, num2, punto, tiro, i;
    num1 = rand() % 6 + 1;
    num2 = rand() % 6 + 1;
    tiro = num1 + num2;

    printf("El jugador tiro %d + %d = %d \n", num1, num2, tiro);
    if (tiro == 2 || tiro == 3 || tiro == 12)
    {
        printf("El jugador pierde\n");
    }
    if (tiro == 7 || tiro == 11)
    {
        printf("El jugador gana\n");
    }
    if (tiro == 4 || tiro == 5 || tiro == 6 || tiro == 8 || tiro == 9 || tiro == 10)
    {
        printf("Tu punto es: %d\n", tiro);
        punto = tiro;
        while (i != 1)
        {
            num1 = rand() % 6 + 1;
            num2 = rand() % 6 + 1;
            tiro = num1 + num2;
            printf("El jugador tiro %d + %d = %d \n", num1, num2, tiro);
            if (punto == tiro)
            {
                printf("El jugador gana\n");
                i++;
            }
            if (tiro == 7)
            {
                printf("El jugador pierde\n");
                i++;
            }
        }
    }

    return 0;
}
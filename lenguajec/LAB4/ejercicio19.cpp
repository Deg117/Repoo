#include <stdio.h>

int main()
{
    int fil, columna;

    for (fil = 1; fil <=8; fil++)
    {
        for (columna = 1; columna <16; columna++)
        {
            if ((fil + columna) % 2 == 0)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    return 0;
}


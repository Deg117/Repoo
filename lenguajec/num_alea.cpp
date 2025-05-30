#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int n, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
    printf("Cara       frecuencia\n");
    for (int num = 0; num < 6001; num++)
    {
        n = (rand() % 5) + 1;
        switch (n)
        {
        case 1:
            n1++;
            break;
        case 2:
            n2++;
            break;
        case 3:
            n3++;
            break;
        case 4:
            n4++;
            break;
        case 5:
            n5++;
            break;
        }
    }
    printf("1%15d\n", n1);
    printf("2%15d\n", n2);
    printf("3%15d\n", n3);
    printf("4%15d\n", n4);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void numaleatorios(void)  //rervisar condiciones para el 100 a 200
{
    int pares = 0, impares = 0;
    float mediapar,sumpar=0;
    srand(time(NULL));

    printf("Numeros generados\n");
    for (int i= 0; i< 25 && pares < 13; i++)
    {
        int num = rand() % 101 + 100;
        if (num % 2 == 0)
        {
            printf("%d - par\n", num);
            pares++;
            sumpar+=num;
        }
        else
        {
            printf("%d - impar\n", num);
            impares++;
        }
        if (pares>0)
        {
            mediapar=sumpar / pares;
        }
        else
        {
            mediapar=0;
        }
    }
    printf("Media de numeros par: %.2f\n", mediapar);
    printf("Cantidad par: %d\n", pares);
    printf("Cantidad impar: %d\n", impares);
}
int main()
{
    numaleatorios();
    return 0;
}
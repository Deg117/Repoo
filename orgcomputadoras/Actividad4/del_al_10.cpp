// Brian de Jesus Gastelum Fierro mat:373408
// Mostrar numeros del 1 al 10
// 18-feb-2025
// BGF_ACT4.CPP
#include <stdio.h>
int main()
{
    int i,sum=0;
    for (i = 1; i <= 10; i++)
    {
        sum=sum+i;
        printf("%d\n", i);
    }
printf ("La suma de los 10 numeros es %d\n",sum );
    return 0;
}


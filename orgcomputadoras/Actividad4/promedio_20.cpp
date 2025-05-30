// Brian de Jesus Gastelum Fierro mat:373408
// suma y promedio de 20 numeros
// 18-feb-2025
// BGF_ACT4.CPP
#include <stdio.h>
#define N 20
int main()
{
    float i,n, sum = 0, prom;
    for (i = 1; i <= N; i++)
    {
        printf("Dame 20 numeros y te mostrare la suma y su promedio \n");
        scanf("%f", &n);
        sum = sum + n;
    }
    prom = sum / N;
    printf("La suma total es %.2f\n", sum);
    printf("El promedio es %.2f\n", prom);
    return 0;
}
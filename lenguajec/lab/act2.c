
#include <stdio.h>
#include <math.h>

int main() 
{
    float p = 100000.0,r = 0.07,monto;
    
    printf("\nAnos     Monto Depositado Final\n");
    monto = p * pow(1 + r, 10);
    printf("10     %.2f\n", monto);
    monto = p * pow(1 + r, 20);
    printf("20     %.2f\n", monto);
    monto = p * pow(1 + r, 30);
    printf("30     %.2f\n", monto);
    return 0;
}


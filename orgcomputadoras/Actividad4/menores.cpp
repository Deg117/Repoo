// Brian de Jesus Gastelum Fierro mat:373408
// Numeros Menores a n, Suma y Promedio
// 21-feb-2025
// BGF_ACT4.CPP
#include <stdio.h>

void nmenores(int n) {
    int sum = 0;
    printf("Numeros menores a n en orden descendente:\n");
    for (int i = n - 1; i > 0; i--) {
        printf("%d\n", i);
        sum += i;
    }
    printf("Suma: %d\n", sum);
    printf("Promedio: %.2f\n", (float)sum / (n - 1));
}

int main() {
    int n;
    printf("Dame un numero: ");
    scanf("%d", &n);
    
    if (n > 1) {
        nmenores(n);
    } else {
        printf("El numero debe ser mayor a 1\n");
    }
    
    return 0;
}
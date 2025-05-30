#include <stdio.h>

int main() {
    int contador = 1, num, mayor1 = 0, mayor2 = 0;
    while (contador <= 10) {
        printf("Dame un numero: ");
        scanf("%d", &num);
        if (num > mayor1) {
            mayor2 = mayor1;  
            mayor1 = num;    
        } else if (num > mayor2) {
            mayor2 = num;  
        }
        contador++;
    }
    printf("Los numeros mayores son: %d y %d\n", mayor1, mayor2);
    return 0;
}

#include <stdio.h>

int main() {
    int contador = 1, num, mayor = 0;
    
    while (contador <= 10) {
        printf("Introduzca un numero: ");
        scanf("%d", &num);
        if (num > mayor) {
            mayor = num;
        }
        contador++;
    }
    printf("El numero mayor es: %d\n", mayor);
    return 0;
}
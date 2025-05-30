#include <stdio.h>

int main() {
    int cantidad, num, sum = 0;
 
    printf("Dame la cantidad de numeros a sumar: ");
    scanf("%d", &cantidad);

    for (int i = 0; i < cantidad; i++) {
        printf("Dame un numero entero: ");
        scanf("%d", &num);
        sum += num;
    }
 
    printf("La suma es: %d\n", sum);
    
    return 0;
}

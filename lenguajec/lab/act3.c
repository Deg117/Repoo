

#include <stdio.h>

int main() {
    int num, ult;
    printf("Ingrese un numero entero y te dire cual es el ultimo numero: ");
    scanf("%d", &num);
    ult= num % 10;
    printf("El ultimo digito del nuumero %d es %d\n", num, ult);
    
    return 0;
}

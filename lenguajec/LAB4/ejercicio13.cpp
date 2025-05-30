#include <stdio.h>

int main() {
    int num, numorigi, digito, invertido = 0;

    printf("Ingresa un numero entero: ");
    scanf("%d", &num);
    numorigi = num; 

    while (num > 0) {
        digito = num% 10;          
        invertido = invertido * 10 + digito; 
        num = num / 10;           
    }
    if (numorigi == invertido) {
        printf("El numero %d es capicua.\n", numorigi);
    } else {
        printf("El numero %d no es capicua.\n", numorigi);
    }
    return 0;
}

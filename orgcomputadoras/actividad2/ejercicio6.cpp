//Brian de Jesus Gastelum Fierro   mat:373408
//numero mayor
//7-feb-2025
//BGF_ACT2.CPp
#include <stdio.h>
int main() {
    int numeros[7];
    int mayor;
    for (int i = 0; i < 7; i++) {
    printf("Ingrese el numero %d: ", i + 1);
    if (scanf("%d", &numeros[i]) != 1) {  
    printf("Entrada invalida. Intente de nuevo.\n");
    return 0;
    }
    }
    mayor = numeros[0];
    for (int i = 1; i < 7; i++) {
    if (numeros[i] > mayor) {
    mayor = numeros[i];
    }
    }
    printf("El mayor de los numeros ingresados es: %d\n", mayor);
    return 0;
}
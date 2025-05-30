#include <stdio.h>

int main() {
    int numBin, digi, deci = 0, potencia = 1;
    printf("Ingresa un numero binario: ");
    scanf("%d", &numBin);
    while (numBin > 0) {
        digi = numBin % 10;            
        deci = deci + digi* potencia;  
        potencia = potencia * 2;               
        numBin = numBin / 10;     
    }
    printf("El numero binario en decimal es: %d\n", deci);
    return 0;
}

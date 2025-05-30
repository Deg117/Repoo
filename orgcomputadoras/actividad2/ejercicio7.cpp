//Brian de Jesus Gastelum Fierro  mat:373408
//calculadora basica
//7-feb-2025
//BGF_ACT2.CPP
#include <stdio.h>
int main() {
    int opcion, num1, num2, r;
    printf("Seleccione una operacion:\n 1. Suma\n 2. Resta\n 3. Multiplicacion\n 4. Division\n Ingrese su opcion:");
    scanf("%d", &opcion);
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    switch(opcion) {
    case 1:
    r= num1 + num2;
    printf("Resultado de la suma: %d\n", r);
    break;
    case 2:
    r= num1 - num2;
    printf("Resultado de la resta: %d\n", r);
    break;
    case 3:
    r = num1 * num2;
    printf("Resultado de la multiplicacion: %d\n", r);
    break;
    case 4:
    if (num2 != 0) {
    printf("Resultado de la division: %f\n", (float)num1 / num2);
    } else {
    printf("Error: Division por cero no permitida.\n");
    }
    break;
    default:
    printf("Opción no valida.\n");
    }
    return 0;
}
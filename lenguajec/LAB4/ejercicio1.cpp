/*Pseudocodigo
inicializamos nuestras variables que vamos a utilizar en este ejercicio
leer numCuenta
usamos nuestro primer while el cual nos ayuda mientras numCuenta no sea -1
para que este se repita hasta que se ingrese el -1
leer saldoInicial
leer totalCargos
leer totalCreditos
leer limiteCredito
hacemos la operscion para el saldo
calcular saldoNuevo = saldoInicial + totalCargos - totalCreditos
verificaos si el saldo es mayor o igual al credito limite y dependiendo del caso imprimimos uno de los mensajes.
if saldoNuevo es mayor o igual que limiteCredito
imprimir "Cuenta: ", numCuenta
imprimir "Límite de crédito excedido"
Fin if
volvemos a leer el numero de cuenta para saber si llega a salir
leer numCuenta
fin while

*/
#include <stdio.h>

int main()
{
    // falta gregar ciclo para que se repita
    int numCuenta;
    float saldoInicial, totalCargos, totalCreditos, limiteCredito, saldoNuevo;

    printf("Introduzca el numero de cuenta: (-1 para finalizar) ");
    scanf("%d", &numCuenta);
    while (numCuenta != -1)
    {

        printf("Introduzca el saldo inicial: ");
        scanf("%f", &saldoInicial);
        printf("Introduzca el total de cargos: ");
        scanf("%f", &totalCargos);
        printf("Introduzca el total de los créditos : ");
        scanf("%f", &totalCreditos);
        printf("Introduzca el limite de creditos: ");
        scanf("%f", &limiteCredito);
        saldoNuevo = saldoInicial + totalCargos - totalCreditos;
        if (saldoNuevo >= limiteCredito)
        {
            printf("cuenta: %d\n", numCuenta);
            printf("Limite de credito: %.2f\n", limiteCredito);
            printf("Saldo %.2f\n", saldoNuevo);
            printf("Límite de crédito excedido\n");
        }
        printf("Introduzca el numero de cuenta: (-1 para finalizar) ");
        scanf("%d", &numCuenta);
    }
    return 0;
}

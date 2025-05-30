//Brian de Jesus Gastelum Fierro  mat:373408
//Llamadas Telefónicas
//8-feb-2025
//BGF_ACT2.CPP
#include <stdio.h>
int main() {
    int tipo;
    float minutos, subtotal = 0, iva, total;
    printf("Calculadora de costo de llamada\n");
    printf("Seleccione el tipo de llamada:\n");
    printf("1. Llamada Local ($3.00 sin limite)\n");
    printf("2. Llamada Nacional ($7.00 por 3 minutos, $2.00 por minuto adicional)\n");
    printf("3. Llamada Internacional ($9.00 por 2 minutos, $4.00 por minuto adicional)\n");
    do {
    printf("Ingrese el tipo de llamada (1-3): ");
    if (scanf("%d", &tipo) != 1 || tipo < 1 || tipo > 3) {
    printf("Entrada no valida. Ingrese un numero entre 1 y 3.\n");
    while (getchar() != '\n');
    continue;
    }
    break;
    } while (1);
    do {
    printf("Ingrese la duracion en minutos: ");
    if (scanf("%f", &minutos) != 1 || minutos <= 0) {
    printf("Entrada no valida. Ingrese un numero positivo.\n");
    while (getchar() != '\n');
    continue;
    }
    break;
    } while (1);
    switch (tipo) {
    case 1:
    subtotal = 3.00;
    break;
    case 2:
    if (minutos <= 3)
    subtotal = 7.00;
    else
    subtotal = 7.00 + (minutos - 3) * 2.00;
    break;
    case 3:
    if (minutos <= 2)
    subtotal = 9.00;
    else
    subtotal = 9.00 + (minutos - 2) * 4.00;
    break;
    }
    iva = subtotal * 0.16;
    total = subtotal + iva;
    printf("Subtotal: $%f\n", subtotal);
    printf("IVA (16%%): $%f\n", iva);
    printf("Total a pagar: $%f\n", total);
    return 0;
}
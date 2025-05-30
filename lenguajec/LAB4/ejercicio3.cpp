/*
inicializamos las variables a utilizar, intereses ,prestamos,dias y tasa 
pedimos el monto del prestamo
leer prestamo
usamos un while para que mientras el prestamo no sea -1 se repita el ciclo
pedimos los siguientes datos
leer tasa
leer dias 
sacamos los intereses
y mostramos la cantidad de intereses 
volvemos a pedir el prestamo para ver si desea salir del programa
cerramos while
fin
*/

#include <stdio.h>
int main() // revisar el pq no se imprimen los %c
{
  float interes, prestamo, dias, tasa;
  printf("Introduzca el monto del prestamo (-1 para terminar):");
  scanf("%f", &prestamo);
  while (prestamo != -1)
  {
    printf("Introduzca la tasa de interes:");
    scanf("%f", &tasa);
    printf("Introduzca el periodo del prestamo en dias:");
    scanf("%f", &dias);
    interes = prestamo * tasa * dias / 365;
    printf("El monto de interes es :$%.2f", interes);
    printf("\n");
    printf("Introduzca el monto del prestamo (-1 para terminar):");
    scanf("%f", &prestamo);
  }
  return 0;
}
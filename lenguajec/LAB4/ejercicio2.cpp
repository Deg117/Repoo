/*Pseudocodigo
iniciamos las variables que vamos a usar en este caso ventas,salario y vendedor
leemos el numero de ventas
Usamos un while que mientras las ventas no sea -1 este se repite
sacamos el salario     
Calcular salario = 200 + (ventas * 0.09)
    mostramos el salario
    volvemos a leer las ventas para ver si ya quiere salir del programa
    Leer ventas
Fin Mientras

*/

#include <stdio.h>

int main()
{
  float ventas, salario;
  int vendedor;

  printf("Indrouzca las ventas en pesos (-1 para terminar):");
  scanf("%f", &ventas);
  while (ventas != -1)
  {
    salario = 200 + (ventas * 0.09);
    printf("El salario es: $%.2f", salario);
    printf("\n");
    printf("Indrouzca las ventas en pesos (-1 para terminar):");
    scanf("%f", &ventas);
  }
  return 0;
}
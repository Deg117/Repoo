//Brian de Jesus Gastelum Fierro  mat:373408
//Calculo de salario
//7-feb-2025
//BGF_ACT2.CPP
#include <stdio.h>

int main() {
  int ht;
  float sh, sal, he = 0;
  printf("Dame las horas trabajadas en la semana: ");
  while (scanf("%d", &ht) != 1 || ht < 0) {
  printf("Entrada invalida. Intenta de nuevo: ");
  while (getchar() != '\n');
  }
  printf("Dame el salario por hora: ");
  while (scanf("%f", &sh) != 1 || sh < 0) {
  printf("Entrada invalida. Intenta de nuevo: ");
  while (getchar() != '\n');
  }
  if (ht <= 40) {
  sal = ht * sh;
  } else {
  he = ht - 40;
  if (he <= 9) {
  sal = (40 * sh) + (he * sh * 2);
  } else {
  sal = (40 * sh) + (9 * sh * 2) + ((he - 9) * sh * 3);
  }
  }
  printf("El salario es %.2f\n", sal);
  return 0;
}
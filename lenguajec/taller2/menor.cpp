#include <stdio.h>

int main()
{
  float a, b, c, menor;

  printf("Ingrese el primer numero: ");
  scanf("%f", &a);
  printf("Ingrese el segundo numero: ");
  scanf("%f", &b);
  printf("Ingrese el tercer numero: ");
  scanf("%f", &c);
  menor = a;
  if (b < menor)
  {
    menor = b;
  }
  if (c < menor)
  {
    menor = c;
  }
  printf("El numero menor es: %.2f\n", menor);

  return 0;
}
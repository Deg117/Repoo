// Brian de Jesus Gastelum Fierro mat:373408
// Tabla de multiplicar
// 18-feb-2025
// BGF_ACT4.CPP
#include <stdio.h>

int main()
{
  int n;
  printf("Dame un numero y te dare su tabla de multiplicar\n");
  scanf("%d", &n);
  printf("Tabla del %d:\n", n);
  for (int i = 1; i <= 10; i++)
  {
    printf("%d x %d = %d\n", n, i, n * i);
  }

  return 0;
}
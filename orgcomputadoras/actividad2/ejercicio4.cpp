//Brian de Jesus Gastelum Fierro mat:373408
//Numero intermedio
//7-feb-2025
//BGF_ACT2.CPP
#include <stdio.h>
int main() {
   int num1, num2, num3, inter;
   printf("Dame el primer numero: ");
   while (scanf("%d", &num1) != 1) {
       printf("Entrada invalida. Intenta de nuevo: ");
       while (getchar() != '\n');
   }
   printf("Dame el segundo numero: ");
   while (scanf("%d", &num2) != 1) {
       printf("Entrada invalida. Intenta de nuevo: ");
       while (getchar() != '\n');
   }
   printf("Dame el tercer numero: ");
   while (scanf("%d", &num3) != 1) {
       printf("Entrada invalida. Intenta de nuevo: ");
       while (getchar() != '\n');
   }
   if ((num1 > num2 && num1 < num3) || (num1 > num3 && num1 < num2)) {
       inter = num1;
   } else if ((num2 > num1 && num2 < num3) || (num2 > num3 && num2 < num1)) {
       inter = num2;
   } else {
       inter = num3;
   }
   printf("El numero intermedio es %d\n", inter);
   return 0;
}
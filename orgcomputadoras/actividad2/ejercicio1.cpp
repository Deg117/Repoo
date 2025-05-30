//Brian de Jesus Gastelum Fierro mat:373408
//Calculo de costos de un terreno
//6-feb-2025
//BGF_ACT2.CPP
#include <stdio.h>
int main ()
{float lar,anch,perim,area,costot,alam;
 float pasto=35.40;
 do { printf("Dame el largo del terreno: ");
 if (scanf("%f", &lar) != 1 || lar <= 0) {
 printf("Entrada no valida. Ingresa un numero positivo.\n");
 while (getchar() != '\n');
 continue; }
 break;
 } while (1);
 do {printf("Dame el ancho del terreno: ");
 if (scanf("%f", &anch) != 1 || anch <= 0) {
 printf("Entrada no valida. Ingresa un numero positivo.\n");
 while (getchar() != '\n');
 continue;}
 break;
 } while (1);
 area = lar * anch;
 perim = 2 * (lar + anch);
 costot = area * pasto;
 alam = perim;
 printf("El costo total para el pasto es: %f pesos\n", costot);
 printf("El alambre a usar es: %f metros\n", alam);
 return 0;
}

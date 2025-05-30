#include <stdio.h>
//Elabore un programa que:
//Solicite las dimensiones de un terreno rectangular (largo y ancho)
//Calcule y muestre:
//El costo total de sembrar pasto (considerando $35.40 por metro cuadrado)
//La cantidad de alambre necesario para cercar el perímetro
int main ()
{
double largo,ancho,perimetro,area,costot,alambre;
double pasto=35.40;
printf("Dame el largo del tereno");
scanf("%lf",&largo);

printf("Dame el ancho");
scanf("%lf",&ancho);
area=largo*ancho;
perimetro=2*(largo+ancho);
costot=area*pasto;
alambre=perimetro;

printf("El costo total para el pasto es: %lf pesos\n",costot);
printf("El alambre a usar es: %lf metros",alambre);
return 0;
}

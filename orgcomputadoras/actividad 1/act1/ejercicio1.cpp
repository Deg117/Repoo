#include <stdio.h>
//Desarrolle un programa que Solicite al usuario el radio 
//y la altura de un cilindro Calcule su volumen  Muestre el resultado con formato adecuado
int main ()
{    
double altura,radio,volumen;
double pi=3.14159;


printf("Dame la altura del cilindro:");
scanf ("%lf",&altura);

printf("Dame el radio del cilindro:");
scanf ("%lf",&radio);

volumen=( pi*(radio*radio))*altura; 
printf("El volumen es: %lf",volumen);
return 0;
}
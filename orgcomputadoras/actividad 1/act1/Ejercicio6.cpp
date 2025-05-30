#include <stdio.h>
//Elabore un programa que:
//Lea 7 números
//Determine y muestre el mayor de ellos
int main()
{
 int numeros[7], mayor;
 for (int i = 0; i < 7; i++) 
 {printf("Dame el numero %d: ", i + 1);
 scanf("%d", &numeros[i]);}
 mayor=numeros[0];
 for (int i=1; i<7; i++){
    if(numeros[i]> mayor){
 }
 }
printf("El numero mayor es %d",mayor);




return 0;
}

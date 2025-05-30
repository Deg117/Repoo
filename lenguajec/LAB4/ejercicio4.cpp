/*
inicializamos las variables a utilizar como float ,salario, horas y pago
pedimos las horas trabajadas
leer horas
usamos un while para que se repita el ciclo mientras no nos den un -1 para finalizar
pedir el pago por hora
leer pago
con un if else ver si trabajo mas de 40 horas se le saca el pago por horas - el pago de las horas extras trabajadas
si no solo se muestra el pago de las horas trabajadas
volvemos a pedir las horas trabajadas par ver si quiere continuar o salir del programa
cerramos while
fin del programa.

*/
#include <stdio.h>

int main()
{
  float salario,horas_la,pago;
  printf("Introduzca el NO. de horas laboradas (-1 para terminar):");
  scanf("%f",&horas_la);
  while( horas_la !=-1)
  {
   printf("Introduzca el pago por hora del empleado:");
   scanf("%f",&pago);
   
   if (horas_la>40)
   {
   salario= (pago*40)+((horas_la-40)*(pago*1.5));   }
   else 
   {
    salario= horas_la*pago;
   }
   printf("El salario es: %.2f",salario); printf("\n");
   printf("Introduzca el NO. de horas laboradas (-1 para terminar):");
   scanf("%f",&horas_la);
  }
    return 0;
}
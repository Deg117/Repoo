#include <stdio.h>
//Sistema de Calificaciones
//Desarrolle un programa que:
//Lea tres calificaciones
//Calcule el promedio
//Muestre la evaluación correspondiente según la siguiente escala:
int main(){
float cal1,cal2,cal3,promedio;
printf("Dame tu primer calificacion");
scanf("%f",&cal1);
printf("Dame tu segunda calificacion");
scanf("%f",&cal2);
printf("Dame tu tercer calificacion");
scanf("%f",&cal3);
promedio=(cal1+cal2+cal3) / 3;
printf ("Tu promedio es %f",promedio);
if (promedio > 100)
{printf ("Error en promedio");   
}
else if (promedio >=98)
{printf("Excelente");    
}
else if (promedio>=90)
{printf("MUY bien");
}
else if (promedio>=80)
{printf("Bien");
}
else if(promedio>=70)
{printf("Regular");
}
else if(promedio>=60)
{ printf("suficiente");
}
else if (promedio>=30)
{printf("Extraordinario");
}
else {
printf("Evaluacion: Repetir");
}return 0;
}
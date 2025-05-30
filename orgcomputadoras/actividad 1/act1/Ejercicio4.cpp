#include <stdio.h>
//Implemente un algoritmo que:
//Lea tres números diferentes
//Determine y muestre cuál es el valor intermedio
int main()
{
 int num1,num2,num3,intermedio;
 printf("Dame el primer numero");
 scanf("%d",&num1);
 printf("Dame el segundo numero");
 scanf("%d",&num2);
 printf("Dame el tercer numero");
 scanf("%d",&num3);
 if((num1>num2 && num1<num3)||(num1>num3 && num1<num2))
 {intermedio= num1;
 }else if ((num2>num1 && num2<num3)||(num2>num3 && num2<num1))
 {intermedio=num2;
 } 
 else {intermedio=num3;
    }{
 printf("El numero intermedio es %d",intermedio);}
   return 0;
}
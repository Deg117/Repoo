#include <stdio.h>

int main(){
 int a,b,c;
 printf("Ingrese el valor entero de a: ");
 scanf("%d",&a);
 printf("Ingrese el valor entero de b: ");
 scanf("%d",&b);
 c=a;
 a=b;
 b=c;
 printf("El valor de la variable a lo contiene b y es b= %d \n",b);
 printf("El valor de la variable b lo contiene a y es a= %d \n",a);

    return 0;
}
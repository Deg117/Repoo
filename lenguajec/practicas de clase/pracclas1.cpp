//PRACTICA DE CLASE #1
//ALUMNOS: JORGE ABRAHAM GARCIA SOJO
//         BRIAN GASTELUM FIERRO 
#include <stdio.h>
int main ()
{
    int a,b,c,tem;
    printf("Dame 3 numeros enteros y los acomodare de menor a mayor");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if (a>b)
    {
        tem=a;
        a=b;
        b=tem;
    }
    if (b>c)
    {
        tem=b;
        b=c;
        c=tem;
    }
    if(a>b)
    {
        tem=a;
        a=b;
        b=tem;
    }
    printf("%d %d %d",a,b,c);
    return 0;
}
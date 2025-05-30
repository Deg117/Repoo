/*el maximo comun divisor (mcd) de dos o mas numeros enteros es el numero entero mas grande que divide a todos ellos sin dejar residuo
tambien se le conoce como el maximo factor comun (MFC) o el divisor comun mayor (DCM)
considere los numeros 12 y 18
los divisores de 12 son: 1,2,3,4,6,12
los divisores de 18 son: 1,2,3,6,9,18
Los divisores comunes de 12 y 18 son 1,2,3 y 6

implementa un scrip iterativo utilizando las estructuras de repeticion para obtener el maximo comun divisor que resiva dos parametros
enteros positivos.Definir una funcion maximo comun divisor que resiva dos parametros enteros a y b, y regrese el maximo comun divisor
de esos dos numeros*/

#include <stdio.h>
int max_comun_divisor(int a, int b);
int main()
{
    int a, b, c;
    printf("Introduzca el dos enteros positivos para mostrar el MCD\n");
    scanf("%d", &a);
    scanf("%d", &b);
    c = max_comun_divisor(a, b);
    printf("El MCD de %d y %d es:%d\n",a,b,c );
    return 0;
}

int max_comun_divisor(int a, int b)
{
    int i = 10000;
    do
    {
       if (a%i==0 && b%i==0)
       {
        return i;
       }
        i--;
    } while ( i!= 0);
}
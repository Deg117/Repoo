
#include <stdio.h>
int main()
{
    int num,res;
   
    printf("Ingrese un numero entero: ");
    scanf("%d", &num);
    res=num%2;
    if (res==0) 
    {
        printf("El numero %d es par.\n", num);
    }
    if (res!=0)
    {
        printf("El numero %d es Impar.\n", num);
    }

    return 0;
}




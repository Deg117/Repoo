//  Brian de jesus Gastelum Fierro
//  Matricula:373408
//  Lectura de numeros dentro de un rango
//  25/feb/2025
//  BGF_ACT5_.CPP
#include <stdio.h>

void nrango(void)
{
    int n1, i = 0, sum = 0, j = 0, porcentaje, incorrec;
    
    printf("Dame un valor entre 10 y 50 ( 0 para finalizar):\n");
    scanf("%d", &n1);

    while (n1 != 0) 
    {
        if (n1 >= 10 && n1 <= 50) 
        {
            sum = sum + n1; 
            j++;             
        } 
        i++;  
        
        printf("Dame un valor entre 10 y 50 ( 0 para finalizar):\n");
        scanf("%d", &n1);
    }

    if (i > 0) 
    {
        porcentaje = (j * 100) / i;  
        incorrec = i - j;             
        printf("La cantidad de numeros son %d\n", i);
        printf("La suma de numeros correctos son %d\n", sum);
        printf("La cantidad de numeros incorrectos son %d\n", incorrec);
        printf("Porcentaje de numeros correctos: %d%%\n", porcentaje);
    } 
    else 
    {
        printf("No se han ingresado numeros validos.\n");
    }
}


int main()
{
    nrango();
    return 0;
}

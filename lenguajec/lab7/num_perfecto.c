#include <stdio.h>
/*se dice que un numero entero es un numero perfecto
6 es un numero perfecto debido a que 6=1+2+3.escriba un numero perfecto
utilice una programa que determine e imprima los numeros perfectos entre 1 y 1000.imprima
los factores de cada numero perfecto para confirmar que el numero es realmente perfecto
hasta que numero encontro un numero perfecto y cuanto tardo?
intento con un numero como el 1,000,000,000,000?
*/
#include <stdio.h>

int numperfecto(int n);
int secuencia(int n);

int main()
{
    int n;
    for (n = 1; n <= 1000; n++)
    {
        if (numperfecto(n) == n)
        {
            secuencia(n);
        }
    }
    return 0;
}

int numperfecto(int n)
{
    int suma = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            suma += i;
        }
    }
    return suma;
}

int secuencia(int n)
{
    int a = 1;
    printf("%d El numero es pefecto por que", a);
    int suma = 0;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            suma += i;
            printf("%d", i);
            if (suma < n)
                printf(" + ");
            a++;
        }
    }
    printf(" = %d\n\n", n);
}

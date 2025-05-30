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

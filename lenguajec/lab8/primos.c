// Numeros primos
// 1/5/2025
// LC_L4_9_rey_rodriguez.cpp
#include <stdio.h>
#include <math.h>
#include <time.h>
int es_primo(int num);
int es_primo_impares(int num);
int es_primo_raiz(int num);

int main()
{
    int limite = 10000;
    clock_t inicio, fin;
    double tiempo1, tiempo2, tiempo3;

    inicio=clock();
    for (int iteracion = 1; iteracion <= limite; iteracion++)
    {
        if (es_primo(iteracion))
        {
            printf("%6d", iteracion);
        }
        else
        {
            printf("%6d", 0);
        }
        if (iteracion % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    fin=clock();
    tiempo1 = double(fin - inicio)/CLOCKS_PER_SEC;

    inicio=clock();
    printf("\n");
    for (int iteracion = 1; iteracion <= limite; iteracion++)
    {
        if (es_primo_impares(iteracion))
        {
            printf("%6d", iteracion);
        }
        else
        {
            printf("%6d", 0);
        }
        if (iteracion % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    fin=clock();
    tiempo2=double(fin-inicio)/CLOCKS_PER_SEC;

    inicio=clock();
    printf("\n");
    for (int iteracion = 1; iteracion <= limite; iteracion++)
    {
        if (es_primo_raiz(iteracion))
        {
            printf("%6d", iteracion);
        }
        else
        {
            printf("%6d", 0);
        }
        if (iteracion % 10 == 0)
        {
            printf("\n");
        }
    }
    fin=clock();
    tiempo3=double(fin-inicio)/CLOCKS_PER_SEC;

    printf("El tiempo de ejecucion de la 1ra funcion fue: %f segundos\n",tiempo1);
    printf("El tiempo de ejecucion de la 2da funcion fue: %f segundos\n",tiempo2);
    printf("El tiempo de ejecucion de la 3ra funcion fue: %f segundos\n",tiempo3);

    return 0;
}

int es_primo(int num)
{

    if (num <= 1)
    {
        return 0;
    }

    for (int num_div = 2; num_div < num; num_div++)
    {
        if (num % num_div == 0)
        {
            return 0;
        }
    }
    return 1;
}

int es_primo_impares(int num)
{

    if (num <= 1)
    {
        return 0;
    }
    if (num == 2)
    {
        return 1;
    }
    if (num % 2 == 0)
    {
        return 0;
    }

    for (int num_div = 3; num_div < num; num_div += 2)
    {
        if (num % num_div == 0)
        {
            return 0;
        }
    }
    return 1;
}

int es_primo_raiz(int num)
{

    if (num <= 1)
    {
        return 0;
    }
    if (num == 2)
    {
        return 1;
    }
    if (num % 2 == 0)
    {
        return 0;
    }

    for (int num_div = 3; num_div < sqrt(num); num_div += 2)
    {
        if (num % num_div == 0)
        {
            return 0;
        }
    }
    return 1;
}
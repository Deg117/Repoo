#include <stdio.h>

int cuadrado(int y);

int main()
{
    int x;
     for (x = 1; x <= 10 ;x++)
    {
        printf("%d\n", cuadrado(x));
    }
    return 0;
}

int cuadrado(int y)
{
    y=y*y;
    return y;
} 
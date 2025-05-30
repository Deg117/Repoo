#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    double d, r1, r2, real, imag;
    a = 2,b = 3,c = 6;
    d = b * b - 4 * a * c;
    if (d >= 0)
    {
        r1 = (-b + sqrt(d)) / (2 * a);
        r2 = (-b - sqrt(d)) / (2 * a);
        printf("Raices: %lf y %lf\n", r1, r2);
    }
    else
    {
        real = -b / (2.0 * a);
        imag = sqrt(-d) / (2.0 * a);
        printf("Raices complejas: %lf + %lf*i y %lf - %lf*i\n", real, imag, real, imag);
    }
    a = 2,b = 15,c = 6;
    d = b * b - 4 * a * c;
    if (d >= 0)
    {
        r1 = (-b + sqrt(d)) / (2 * a);
        r2 = (-b - sqrt(d)) / (2 * a);
        printf("Raices: %lf y %lf\n", r1, r2);
    }
    else
    {
        real = -b / (2.0 * a);
        imag = sqrt(-d) / (2.0 * a);
        printf("Raices complejas: %lf + %lf*i y %lf - %lf*i\n", real, imag, real, imag);
    }

    return 0;
}
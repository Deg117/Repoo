#include <stdio.h>

int diferencia(int h1, int m1, int s1, int h2, int m2, int s2);

    int main()
{
    int h1, m1, s1, h2, m2, s2, dif;

    printf("Ingrese la primera hora (horas minutos segundos): ");
    scanf("%d %d %d", &h1, &m1, &s1);

    printf("Ingrese la segunda hora (horas minutos segundos): ");
    scanf("%d %d %d", &h2, &m2, &s2);

    dif = diferencia(h1, m1, s1, h2, m2, s2);

    printf("La diferencia en segundos entre las dos horas (en un ciclo de 12 horas) es: %d\n", dif);

    return 0;
}

int diferencia(int h1, int m1, int s1, int h2, int m2, int s2)
{
    int seg1 = h1 * 3600 + m1 * 60 + s1;
    int seg2 = h2 * 3600 + m2 * 60 + s2;

    int dif = seg2 - seg1;

    if (dif < 0)
    {
        dif += 12 * 3600;
    }

    return dif;
}
#include <stdio.h>

void derecho_examen(void)
{
    int alumnos = 40, sinderecho = 0, calif;
    float prom;
    for (int i = 1; i <= alumnos; i++)
    {
        float suma = 0;
        printf("Dame las 5 calificaciones del alumno\n");
        for (int j = 1; j < 5; j++)
        {
            printf("calificacion %d\n", j);
            scanf("%d", &calif);
            suma += calif;
        }
        prom = suma / 5;
        printf("El promedio de este alumno es %.2f\n", prom);
        if (prom < 50)
        {
            sinderecho++;
        }
    }

    printf("Los alumnos sin derecho a examen son %d\n", sinderecho);
}

int main()
{
    derecho_examen();
    return 0;
}
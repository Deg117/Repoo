/*Inicializacion









*/

#include <stdio.h>
int main()
{
    float calif, total, prom, aprobados, reprobados;
    aprobados = 0;
    reprobados = 0;

    while (calif == 0)
    {
        printf("Ingresa las calificaciones (0 para finalizar)\n");
        scanf("%d", &calif);
        if (calif < 0)
        {
            printf("La calificacipn está fuera del rango establecido, por favor ingrese una calificacion entre 0 y 100\n");
            return 20;
        }
        if (calif >= 60)
        {
            aprobados++;
        }
        if (calif < 60)
        {
            reprobados++;
        }
        prom = total ;

    }
if (prom>=90)
{
    printf("El docente obtuvo un buen desempeño en el segundo parcial\n");
printf("El promedio grupal es %.1f\n",prom);
printf("Aprobados: %.0f\n reprobados:%.f",aprobados,reprobados);
}
if (prom<90)
{
    printf("El docente no obtuvo un buen desempeño en el segundo parcial\n");
    printf("El promedio grupal es %.1f\n",prom);
    printf("Aprobados: %.0f\n reprobados:%.f",aprobados,reprobados);
}
    return 0;
}

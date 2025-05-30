//Brian de Jesus Gastelum Fierro  mat:373408
//Sistema de Calificaciones
//6-feb-2025
//BGF_ACT2.CPP
#include <stdio.h>
int main(){
float cal1,cal2,cal3,prom;
do {printf("Dame tu primera calificacion: ");
    if (scanf("%f", &cal1) != 1 || cal1 < 0 || cal1 > 100) {
    printf("Entrada no valida. Ingresa un numero entre 0 y 100.\n");
    while (getchar() != '\n');
    continue;
    } break;
} while (1);
do {printf("Dame tu segunda calificacion: ");
    if (scanf("%f", &cal2) != 1 || cal2 < 0 || cal2 > 100) {
    printf("Entrada no valida. Ingresa un numero entre 0 y 100.\n");
    while (getchar() != '\n');
    continue;
    }break;
} while (1);
do {printf("Dame tu tercera calificacion: ");
    if (scanf("%f", &cal3) != 1 || cal3 < 0 || cal3 > 100) {
    printf("Entrada no valida. Ingresa un numero entre 0 y 100.\n");
    while (getchar() != '\n');
    continue; }
    break;
} while (1);
prom = (cal1 + cal2 + cal3) / 3;
printf("Tu promedio es %.2f\n", prom);
if (prom > 100) {
    printf("Error en promedio\n");
} else if (prom >= 98) {
    printf("Excelente\n");
} else if (prom >= 90) {
    printf("Muy bien\n");
} else if (prom >= 80) {
    printf("Bien\n");
} else if (prom >= 70) {
    printf("Regular\n");
} else if (prom >= 60) {
    printf("Suficiente\n");
} else if (prom >= 30) {
    printf("Extraordinario\n");
} else {
    printf("Evaluacion: Repetir\n");
}
return 0;
}

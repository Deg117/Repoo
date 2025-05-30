#include <stdio.h>

int main() {
    float radio = 2;
    float pi = 3.14159;
    float diametro, circunferencia, area;
    diametro = 2 * radio;
    circunferencia = 2 * pi * radio;
    area = pi * radio * radio;
    printf("El diámetro es: %f\n", diametro);
    printf("La circunferencia es: %f\n", circunferencia);
    printf("El área es: %f\n", area);
    return 0;
    }

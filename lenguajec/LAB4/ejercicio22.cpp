#include <stdio.h>

int main() {
    float a, b, c;

    printf("Ingresa tres valores: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a > b && a > c) {
        if (a * a == b * b + c * c) {
            printf("Los lados forman un triangulo rectangulo.\n");
        } else {
            printf("Los lados no forman un triangulo rectangulo.\n");
        }
    } else if (b > a && b > c) {
        if (b * b == a * a + c * c) {
            printf("Los lados forman un triangulo rectangulo.\n");
        } else {
            printf("Los lados no forman un triangulo rectangulo.\n");
        }
    } else {
        if (c * c == a * a + b * b) {
            printf("Los lados forman un triangulo rectangulo.\n");
        } else {
            printf("Los lados no forman un triangulo rectangulo.\n");
        }
    }
    return 0;
}

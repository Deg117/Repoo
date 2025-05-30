#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int suma, dado1, dado2;
    int resultados[13] = {0}; // índices 2 a 12

    srand(time(NULL));

    for (int i = 0; i < 36000; i++) {
        dado1 = (rand() % 6) + 1;
        dado2 = (rand() % 6) + 1;
        suma = dado1 + dado2;
        resultados[suma]++;
    }

    printf("Suma\tFrecuencia\n");
    for (int i = 2; i <= 12; i++) {
        printf("%d\t%d\n", i, resultados[i]);
    }

    float porcentaje_7 = (resultados[7] / 36000.0) * 100.0;
    printf("\nPorcentaje esperado de 7: %.2f%%\n", (6.0 / 36.0) * 100.0);
    printf("Porcentaje actual de 7: %.2f%%\n", porcentaje_7);

    return 0;
}

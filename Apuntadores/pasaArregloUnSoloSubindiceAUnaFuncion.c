#include <stdio.h>

// Prototipo de la función utilizando notación de arreglo
void cuboPorReferenciaConArreglo(int arr[], int tamano); 

// Prototipo de la función utilizando notación de apuntadores
void cuboPorReferenciaConApuntador(int *ptr, int tamano);

int main() {
    int miArreglo[] = {1, 2, 3, 4, 5};
    int tamanoArreglo = sizeof(miArreglo) / sizeof(miArreglo[0]);
    int i;

    printf("--- Usando cuboPorReferenciaConArreglo (notaci%cn de arreglo) ---\n", 162);
    printf("Arreglo original: ");
    for (i = 0; i < tamanoArreglo; i++) {
        printf("%d ", miArreglo[i]);
    }
    printf("\n");

    cuboPorReferenciaConArreglo(miArreglo, tamanoArreglo);

    printf("Arreglo despu%cs de cuboPorReferenciaConArreglo: ", 130);
    for (i = 0; i < tamanoArreglo; i++) {
        printf("%d ", miArreglo[i]);
    }
    printf("\n\n");

    // Reiniciamos el arreglo para la segunda demostración
    int otroArreglo[] = {10, 20, 30};
    int tamanoOtroArreglo = sizeof(otroArreglo) / sizeof(otroArreglo[0]);

    printf("--- Usando cuboPorReferenciaConApuntador (notaci%cn de apuntadores) ---\n", 162);
    printf("Otro arreglo original: ");
    for (i = 0; i < tamanoOtroArreglo; i++) {
        printf("%d ", otroArreglo[i]);
    }
    printf("\n");

    cuboPorReferenciaConApuntador(otroArreglo, tamanoOtroArreglo);

    printf("Otro arreglo despu%cs de cuboPorReferenciaConApuntador: ", 130);
    for (i = 0; i < tamanoOtroArreglo; i++) {
        printf("%d ", otroArreglo[i]);
    }
    printf("\n");

    return 0;
}

// Implementación de la función usando notación de arreglo
void cuboPorReferenciaConArreglo(int arr[], int tamano) {
    printf("Dentro de cuboPorReferenciaConArreglo (parametro: int arr[]):\n");
    printf("La direcci%cn de 'arr' aqu%c es la misma que la del inicio del arreglo original en main.\n", 162, 161);
    int i;
    for (i = 0; i < tamano; i++) {
        arr[i] = arr[i] * arr[i] * arr[i]; // Modifica el valor original del arreglo
    }
}

// Implementación de la función usando notación de apuntadores
void cuboPorReferenciaConApuntador(int *ptr, int tamano) {
    printf("Dentro de cuboPorReferenciaConApuntador (parametro: int *ptr):\n");
    printf("La direcci%cn de 'ptr' aqu%c es la misma que la del inicio del arreglo original en main.\n", 162, 161);
    int i;
    for (i = 0; i < tamano; i++) {
        *(ptr + i) = *(ptr + i) * *(ptr + i) * *(ptr + i); // Modifica el valor original del arreglo
        // Alternativamente, se podría usar ptr[i] = ptr[i] * ptr[i] * ptr[i];
        // Demostrando que son intercambiables.
    }
}
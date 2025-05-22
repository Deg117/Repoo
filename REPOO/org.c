#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;

void validarEdad(int edad) {
    if (edad < 18 || edad > 99) {
        printf("Edad fuera de rango permitido. Reintente.\n");
        longjmp(buffer, 1);
    } else {
        printf("Edad valida: %d\n", edad);
    }
}

int main() {
    int edad;

    if (setjmp(buffer) == 0) {
        // Primer intento
        printf("Ingrese su edad: ");
        scanf("%d", &edad);
    } else {
        // Segundo intento
        printf("Ingrese su edad nuevamente: ");
        scanf("%d", &edad);
    }

    validarEdad(edad);
    printf("Fin del programa.\n");
    return 0;
}

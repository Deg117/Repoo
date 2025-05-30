//Brian de Jesus Gastelum Fierro  mat:373408
//piedra papel o tijeras
//8-feb-2025
//BGF_ACT2.CPP
#include <stdio.h>
const char* _ganador(int jugador1, int jugador2) {
    if (jugador1 == jugador2) {
    return "Empate";
    } else if ((jugador1 == 1 && jugador2 == 3) || (jugador1 == 2 && jugador2 == 1) || (jugador1 == 3 && jugador2 == 2)) {
    return "Jugador 1 gana";
    } else {
    return "Jugador 2 gana";
    }
}
int main() {
    int jugador1, jugador2;
    printf("Juego Piedra, Papel o Tijera\n");
    printf("1. Piedra\n2. Papel\n3. Tijera\n");
    do {
    printf("Jugador 1, elige una opción (1-3): ");
    if (scanf("%d", &jugador1) != 1) {
    printf("Entrada no valida. Ingresa un numero.\n");
    while (getchar() != '\n'); 
    continue;
    }
    } while (jugador1 < 1 || jugador1 > 3);
    do {
    printf("Jugador 2, elige una opcion (1-3): ");
    if (scanf("%d", &jugador2) != 1) {
    printf("Entrada no valida. Ingresa un numero.\n");
    while (getchar() != '\n'); 
    continue;
    }
    } while (jugador2 < 1 || jugador2 > 3);
    printf("Resultado: %s\n", _ganador(jugador1, jugador2));
    return 0;
}
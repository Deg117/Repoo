//Brian de Jesus Gastelum Fierro mat:373408
//Juego de Piedra, Papel o Tijera
//15-feb-2025
//BGF_ACT3.CPP
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int j1, comp = rand() % 3 + 1;
    printf("JUEGO DE PIEDRA,PAPEL O TIJERA\n");
    printf("Jugador 1 elija su opcion: \n");
    printf("1. Piedra \n2. Papel\n3. Tijera\n");
    scanf("%d", &j1);
    printf("La computadora elige: %d \n", comp);
    if (j1 == comp)
    {
        printf("Empate");
    }
    else
    {
        if (j1 == 1 && comp == 3 || j1 == 2 && comp == 1 || j1 == 3 && comp == 2)
        {
            printf("Gana el jugador !!!!");
        }
        else
        {
            printf("GANA la computadora!!!!");
        }
    }
    return 0;
}
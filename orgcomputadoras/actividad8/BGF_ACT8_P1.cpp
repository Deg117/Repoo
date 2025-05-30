/*Brian De Jesus Gatelum Fierro
Matricula:373408
parte 1
19/03/2025
BGF_ACT8_PE_.CPP
*/
#include "brian.h"

int main()
{
    int op;
    int vector[15] = {0};
    int matriz[4][4] = {0};

    do
    {
        printf("Menu\n");
        printf("1- LLenar vector\n");
        printf("2- Llenar matriz\n");
        printf("3- Imprimir vector\n");
        printf("4- Imprimir matriz\n");
        printf("5- Ordenar vector\n");
        printf("6- Buscar en el vector\n");
        printf("7- SALIR\n");
        op = validar(1, 7, "Dame una opcion:\n");
        switch (op)
        {
        case 1:
            vector_alea1(vector, 15, 100, 200);
            break;
        case 2:
            matriz_4x4(matriz, 4, 1, 16);
            break;
        case 3:
            imp_vector(vector, 15);
            break;
        case 4:
            imp_matriz(matriz, 4);
            break;
        case 5:
            orden_vect(vector, 15);
            break;
        case 6:
            buscar(vector, 15);
            break;
        case 7:
            printf("Saliendo");
            break;
        }
    } while (op != 7);
    return 0;
}


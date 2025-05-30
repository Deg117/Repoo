/*Brian De Jesus Gatelum Fierro
Matricula:373408
parte 1
14/03/2025-15/03/2025
BGF_ACT7_PE_.CPP
*/
#include "brian.h"
void vector_1(int vector1[], int tamanio);
void vector_2(int vector2[], int tamanio);
void vector_3(int vector1[], int vector2[], int vector3[], int tamanio);
void vectores_123(int vector1[], int vector2[], int vector3[], int tamanio);
void matriz_4x4(int matriz[][4], int vector1[], int vector2[], int tamanio);
void mostrar_matriz(int matriz[10][4], int tamanio);
void cadenas(char cadena[][50], int tamanio);
void mostrar_cadena(char cadena[][50], int tamanio);

int main()
{
    int op;
    int vector1[10] = {0};
    int vector2[10] = {0};
    int vector3[20] = {0};
    int matriz[4][4] = {0};
    char cadena[10][50] = {'\0'};
    do
    {
        printf("Menu\n");
        printf("1.- LLENAR VECTOR 1 (MANUALMENTE)\n");
        printf("2.- LLENAR VECTOR 2 (ALEATORIAMENTE)\n");
        printf("3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)\n");
        printf("4.- IMPRIMIR VECTORES\n");
        printf("5.- LLENAR MATRIZ 4x4\n");
        printf("6.- IMPRIMIR MATRIZ\n");
        printf("7.- VECTOR DE CADENAS\n");
        printf("8.- IMPRIMIR VECTOR DE CADENAS\n");
        printf("9.- SALIR\n");
        op = validar(1, 9, "Dame una opcion:\n");
        switch (op)
        {
        case 1:
            vector_1(vector1, 10);
            break;
        case 2:
            vector_2(vector2, 10);
            break;
        case 3:
            vector_3(vector1, vector2, vector3, 20);
            break;
        case 4:
            vectores_123(vector1, vector2, vector3, 10);
            break;
        case 5:
            matriz_4x4(matriz, vector1, vector2, 4);
            break;
        case 6:
            mostrar_matriz(matriz, 4);
            break;
        case 7:
            cadenas(cadena, 10);
            break;
        case 8:
            mostrar_cadena(cadena, 10);
            break;
        case 9:
            printf("Saliendo");
            break;
        }
    } while (op != 9);
    return 0;
}

void vector_1(int vector1[], int tamanio) // listo
{
    int i, num;
    for (i = 0; i < tamanio; i++)
    {
        num = validar(30, 70, "Dame un numero\n");
        vector1[i] = num;
    }
    printf("Numeros ingresados\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d \n", vector1[i]);
    }
}

void vector_2(int vector2[], int tamanio) // listo
{
    int i, num;
    for (i = 0; i < 10; i++)
    {
        vector2[i] = (rand() % 20) + 1;
    }
    printf("Los numeros ingresados aleatoriamente fueron:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d \n", vector2[i]);
    }
}

void vector_3(int vector1[], int vector2[], int vector3[], int tamanio) // listo
{
    int i;
    for (i = 0; i <= 10; i++)
    {
        vector3[i] = vector1[i];
    }
    for (i = 0; i <= 10; i++)
    {
        vector3[10 + i] = vector2[i];
    }
    vector3[20] = '\0';
    printf("la convinacion de vectores 1 y 2 es:\n");
    for (i = 0; i < 20; i++)
    {
        printf("%d\n ", vector3[i]);
    }
}

void vectores_123(int vector1[], int vector2[], int vector3[], int tamanio) // listo
{
    int i;
    printf("vector 1\tvector 2\tvector 3\t\n");
    for (i = 0; i < 2 * tamanio; i++)
    {
        if (i < tamanio)
        {
            printf("%d\t        %d\t         %d\t\n", vector1[i], vector2[i], vector3[i]);
        }
        else
        {
            printf("\t       \t                 %d\n", vector3[i]);
        }
    }
}

void matriz_4x4(int matriz[][4], int vector1[], int vector2[], int tamanio) // listo
{
    int i, j;
    for (i = 0; i < tamanio; i++)
    {
        for (j = 0; j < tamanio; j++)
        {
            if ((i * tamanio) + j < 10)
            {
                matriz[i][j] = vector1[(i * tamanio) + j];
            }
            else
            {
                matriz[i][j] = vector2[((i * tamanio) + j) - 10];
            }
        }
    }
}

void mostrar_matriz(int matriz[][4], int tamanio) // listo
{
    int i, j;
    for (i = 0; i < tamanio; i++)
    {
        for (j = 0; j < tamanio; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void cadenas(char cadena[][50], int tamanio) // listo
{
    int i, opcion=1;
    // char nombre[50];
    for (i = 0; i < tamanio; i++)
    {
        while (opcion == 0)
        {
            opcion = validar(11, 12, "Quieres continuar?  11 para si, 12 para no\n");
            if (opcion == 12)
            {
                break;
            }
        }
        if (opcion == 12)
        {
            break;
        }
        printf("Dame tu nombre completo:\n");
        my_gets(cadena[i], 50);
        opcion = 0;
        if (i == tamanio - 1)
        {
            printf("El vector se lleno \n");
            break;
        }
    }
}

void mostrar_cadena(char cadena[][50], int tamanio) // listo
{
    int i;
    for (i = 0; i < tamanio; i++)
    {
        printf("%s\n", cadena[i]);
    }
}
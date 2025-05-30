/*Brian De Jesus Gatelum Fierro
Matricula:373408
parte 2
19/03/2025
BGF_ACT8_PE_.CPP
*/
#include "brian.h"
//Prototipos  en libreria 
void sub_menu(int vector[]);
void su_menu(int vector[]);
int main()
{
    int op;
    int vector[10000] = {0};
    int matriz[4][4] = {0};
    vector_alea(vector, 10000, 1, 15000);
    do
    {
        printf("Menu\n");
        printf("1.- Ordenar vector\n");
        printf("2.- Buscar valor en vector\n");
        printf("0.- SALIR\n");
        op = validar(0, 2, "Dame una opcion:\n");
        switch (op)
        {
        case 1:
            sub_menu(vector);
            break;
        case 2:
            su_menu(vector);
            break;
        default:
            printf("Saliendo");
            break;
        }
    } while (op != 0);
    return 0;
}

void sub_menu(int vector[])
{
    int opci;
    do
    {
        printf("SUBMENU\n");
        printf("1- Burbuja (Buble sort)\n");
        printf("2- Seleccion (Selection sort)\n");
        printf("3- Quicksort\n");
        printf("4- Sherllsort\n");
        printf("5- Mergesort\n");
        printf("0- Regresar\n");
        opci = validar(0, 5, "Dame una opcion\n");
         clock_t start = clock();
        switch (opci)
        {
        case 1:
            burbuja(vector, 10000);
            break;
        case 2:
            seleccion(vector, 10000);
            break;
        case 3:
            quicksort(vector, 0, 10000);
            break;
        case 4:
            shellSort(vector, 10000);
            break;
        case 5:
            mergesort_2(vector,0,10000-1);
            break;

        default:
            printf("Regresando a menu\n");
        }
        clock_t end = clock();
        double tiempo = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Tiempo de ejecución: %f segundos\n", tiempo);
    } while (opci != 0);

}

void su_menu(int vector[]) // revisar pq se sale si le doy letras;
{
    int opcion;
    do
    {
        printf("SUBMENU\n");
        printf("1- Secuencial\n");
        printf("2- Binaria\n");
        printf("0- Regresar\n");
        opcion = validar(0, 2, "Dame una opcion\n");
        switch (opcion)
        {
        case 1:
            busqueda_secuencial(vector, 10000);
            break;
        case 2:
            busqueda_bin(vector, 10000);
            break;
        default:
            printf("Regresando a menu\n");
        }

    } while (opcion != 0);
}


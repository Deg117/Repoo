#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define elementos 5
#define num_max 28
#define array_totales 10000
#define combinaciones 98280

// Prototipos de funciones
void generarTodasLasCombinaciones(int arreglo[][elementos]);
void ordenarTodosLosRegistros(int arreglo[][elementos], int t_registros);
bool elementoRepetido(int arreglo[], int elemento);
void generarArregloUnico(int arreglo[]);
void ordenarArregloIndividual(int arreglo[]);
bool verificarArregloRepetido(int arreglo[][elementos], int arreglonuevo[], int total_nuevo);
int compararArreglos(const void *a, const void *b);
void escribirArregloEnArchivoTXT(const char *rutaArchivo, int arreglo[][elementos], int total);
void obtenerGrupo(int arreglo[], char grupo[]);
void escribirArregloEnExcelConPestanas(const char *nombreArchivo, int arreglo[][elementos], int total);

int main()
{
    srand(time(NULL));
    int opcion;
    printf("Seleccione una opcion:\n");
    printf("1. Generar 10,000 combinaciones aleatorias\n");
    printf("2. Generar todas las 98,280 combinaciones posibles\n");
    scanf("%d", &opcion);

    clock_t inicio = clock();

    if (opcion == 1)
    {
        int arreglo[array_totales][elementos];
        int totalGenerados = 0;

        while (totalGenerados < array_totales)
        {
            int arregloActual[elementos] = {0};
            generarArregloUnico(arregloActual);
            ordenarArregloIndividual(arregloActual);

            if (!verificarArregloRepetido(arreglo, arregloActual, totalGenerados))
            {
                for (int i = 0; i < elementos; i++)
                {
                    arreglo[totalGenerados][i] = arregloActual[i];
                }
                totalGenerados++;
            }
        }

        ordenarTodosLosRegistros(arreglo, array_totales);
        escribirArregloEnArchivoTXT("10000_combinaciones.txt", arreglo, array_totales);
        escribirArregloEnExcelConPestanas("10000_combinaciones.xlsx", arreglo, array_totales);
    }
    else if (opcion == 2)
    {
        int arreglo[combinaciones][elementos];
        generarTodasLasCombinaciones(arreglo);
        escribirArregloEnArchivoTXT("todasLasCombinaciones.txt", arreglo, combinaciones);
        escribirArregloEnExcelConPestanas("todas_combinaciones.xlsx", arreglo, combinaciones);
    }

    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.2f segundos\n", tiempo);

    return 0;
}

void ordenarTodosLosRegistros(int arreglo[][elementos], int t_registros)
{
    qsort(arreglo, t_registros, sizeof(int[elementos]), compararArreglos);
}

bool elementoRepetido(int arreglo[], int elemento)
{
    for (int i = 0; i < elementos; i++)
    {
        if (arreglo[i] == elemento)
        {
            return true;
        }
    }
    return false;
}

void generarArregloUnico(int arreglo[])
{
    for (int i = 0; i < elementos; i++)
    {
        int num;
        do
        {
            num = rand() % num_max + 1;
        } while (elementoRepetido(arreglo, num));
        arreglo[i] = num;
    }
}

void ordenarArregloIndividual(int arreglo[])
{
    for (int i = 0; i < elementos - 1; i++)
    {
        for (int j = 0; j < elementos - i - 1; j++)
        {
            if (arreglo[j] > arreglo[j + 1])
            {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

bool verificarArregloRepetido(int arreglo[][elementos], int arreglonuevo[], int total_nuevo)
{
    for (int i = 0; i < total_nuevo; i++)
    {
        bool igual = true;
        for (int j = 0; j < elementos; j++)
        {
            if (arreglo[i][j] != arreglonuevo[j])
            {
                igual = false;
                break;
            }
        }
        if (igual)
            return true;
    }
    return false;
}

int compararArreglos(const void *a, const void *b)
{
    const int *arregloA = (const int *)a;
    const int *arregloB = (const int *)b;

    for (int i = 0; i < elementos; i++)
    {
        if (arregloA[i] > arregloB[i])
            return 1;
        else if (arregloA[i] < arregloB[i])
            return -1;
    }
    return 0;
}

void escribirArregloEnArchivoTXT(const char *rutaArchivo, int arreglo[][elementos], int total)
{
    FILE *archivo = fopen(rutaArchivo, "w");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    char grupo[20];
    for (int i = 0; i < total; i++)
    {
        obtenerGrupo(arreglo[i], grupo);
        fprintf(archivo, "%d %d %d %d %d %s\n",
                arreglo[i][0],
                arreglo[i][1],
                arreglo[i][2],
                arreglo[i][3],
                arreglo[i][4],
                grupo);
    }

    fclose(archivo);
}

void generarTodasLasCombinaciones(int arreglo[][elementos])
{
    int index = 0;
    for (int a = 1; a <= num_max - 4; a++)
    {
        for (int b = a + 1; b <= num_max - 3; b++)
        {
            for (int c = b + 1; c <= num_max - 2; c++)
            {
                for (int d = c + 1; d <= num_max - 1; d++)
                {
                    for (int e = d + 1; e <= num_max; e++)
                    {
                        arreglo[index][0] = a;
                        arreglo[index][1] = b;
                        arreglo[index][2] = c;
                        arreglo[index][3] = d;
                        arreglo[index][4] = e;
                        index++;
                    }
                }
            }
        }
    }
}

void obtenerGrupo(int arreglo[], char grupo[])
{
    int r1 = 0, r2 = 0, r3 = 0;
    for (int i = 0; i < elementos; i++)
    {
        if (arreglo[i] >= 1 && arreglo[i] <= 9)
            r1++;
        else if (arreglo[i] >= 10 && arreglo[i] <= 19)
            r2++;
        else if (arreglo[i] >= 20 && arreglo[i] <= 28)
            r3++;
    }
    sprintf(grupo, "Grupo %d-%d-%d", r1, r2, r3);
}

void escribirArregloEnExcelConPestanas(const char *nombreArchivo, int arreglo[][elementos], int total)
{
    printf("[Excel simulado] Guardando archivo: %s\n", nombreArchivo);
    char grupo[20];
    char grupos_unicos[50][20];
    int n_grupos = 0;

    for (int i = 0; i < total; i++)
    {
        obtenerGrupo(arreglo[i], grupo);
        bool exists = false;
        for (int j = 0; j < n_grupos; j++)
        {
            if (strcmp(grupos_unicos[j], grupo) == 0)
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            strncpy(grupos_unicos[n_grupos], grupo, 20);
            n_grupos++;
        }
    }

    printf("Total de grupos unicos encontrados: %d\n", n_grupos);
}

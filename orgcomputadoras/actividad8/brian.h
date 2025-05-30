#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

char *my_gets(char *cadena, int tamano);
int validar(int ri, int rf, const char *msge);
void principal();
void mayusculas(char texto[]);
void minusculas(char texto[]);
void capital(char texto[]);
void eliminar_espacios(char texto[]);
int caracteres(char texto[]);
int busqueda_secu(int vector[], int m, int val);
void buscar(int vector[], int m);
void ordenar(int vector[], int m);
int busqueda_secu_mat(int matriz[][4], int m, int val);
void burbuja(int vector[], int tam);
void Seleccion(int vect[], int m);
void swichea(int *num1, int *num2);
void quicksort(int vector[], int ri, int rf);
void shellSort(int vector[], int m);
int busqueda_bin(int *vector, int m);
void mergesort_2(int vector[], int izqui, int dere);
void vector_alea(int vector[], int m, int ri, int rf);
void matriz_4x4(int matriz[4][4], int m, int ri, int rf);
void imp_vector(int vector[], int m);
void orden_vect(int vector[], int m);
void imp_matriz(int matriz[][4], int m);
void vector_alea1(int vector[], int m, int ri, int rf);
void vector_alea(int vector[], int m, int ri, int rf);
char *my_gets(char *cadena, int tamano)
{
    size_t longitud;
    fflush(stdin);
    fgets(cadena, tamano, stdin);
    if (cadena)
    {
        longitud = strlen(cadena);
        if (longitud > 0)
        {
            if (cadena[longitud - 1] == '\n')
            {
                cadena[longitud - 1] = '\0';
            }
        }
        return cadena;
    }
    return NULL;
}

int validar(int ri, int rf, const char *msge)
{
    int num;
    char strnum[30];
    do
    {
        printf("%sEntre el %d y %d\n", msge, ri, rf);
        my_gets(strnum, 30);
        num = atoi(strnum);
        if (num < ri || num > rf)
        {
            printf("Dame lo que se pide...\n");
        }
    } while (num < ri || num > rf);
    return num;
}

void principal(char texto[])
{
    printf("Dame un texto y te lo mostrare de las siguientes formas:\n•Mayusculas\n•Minusculas\n•Capital\n•Sin espacios\n");
    my_gets(texto, 50);
    printf("•Mayusculas\n");
    mayusculas(texto);
    printf("•Minusculas\n");
    minusculas(texto);
    printf("•Capital\n");
    capital(texto);
    printf("•Sin espacios\n");
    eliminar_espacios(texto);
}

void mayusculas(char texto[]) // listo
{
    int i;
    // printf("Dame el texto para dartelo en mayusculas:\n");
    // my_gets(texto, 50);
    for (i = 0; i < texto[i] != '\0'; i++)
    {
        if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            texto[i] = texto[i] - 32;
        }
    }
    // printf("La cadena en mayusculas es:\n");
    printf("%s\n", texto);
}

void minusculas(char texto[])
{
    int i;
    // printf("Dame el texto para dartelo en minusculas:\n");
    // my_gets(texto, 50);
    for (i = 0; i < texto[i] != '\0'; i++)
    {
        if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            texto[i] = texto[i] + 32;
        }
    }
    // printf("La cadena en minusculas es:\n");
    printf("%s\n", texto);
}

void capital(char texto[]) // listo
{
    int i, inicio = 1;
    // printf("Dame el texto para dartelo en Capital:\n");
    // my_gets(texto, 50);
    for (i = 0; texto[i] != '\0'; i++)
    {
        if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            if (inicio)
            {
                texto[i] = texto[i] - 32;
                inicio = 0;
            }
        }
        else
        {
            if (texto[i] >= 'A' && texto[i] <= 'Z')

            {
                if (!inicio)
                {
                    texto[i] = texto[i] + 32;
                }
            }
        }
        if (texto[i] == ' ') // para ver si hay espacios
        {
            inicio = 1;
        }
    }
    printf("%s\n", texto);
}

void eliminar_espacios(char texto[])
{
    int i, j = 0, tamano;

    // printf("Dame un texto y le quitare los espacios:\n");
    // my_gets(texto, 50);
    tamano = caracteres(texto);
    for (i = 0; i < tamano; i++)
    {
        if (texto[i] != ' ')
        {
            texto[j] = texto[i];
            j++;
        }
    }
    texto[j] = '\0';
    // printf("La palabra sin espacios es:\n");
    printf("%s\n", texto);
}
int caracteres(char texto[])
{
    int i = 0;
    int total = 0;
    // printf("Dame una palabra para darte la cantidad de caracteres:\n");
    // my_gets(texto, 50);
    while (texto[i] != '\0')
    {
        total++;
        i++;
    }
    // printf("La cantidad de caracteres es:\n");
    // printf("%d\n", total);

    return total;
}
//activad 8 parte 1
void vector_alea1(int vector[], int m, int ri, int rf) // listo
{
    int i, num, rango;
    rango = (rf - ri) + 1;
    for (i = 0; i < m; i++)
    {
        do
        {
            num = (rand() % 101 + 100); // desde 100 a 200
        } while (busqueda_secu(vector, i, num) != -1);
        vector[i] = num; // almacenamos datos validos
    }
}

void matriz_4x4(int matriz[4][4], int m, int ri, int rf) // se queda en el 2 no avanza
{
    for (int i=0;i<m;i++)  //inicializa la matrzi en 0 de nuevo
    {
        for(int j=0;j<m;j++)

        {
            matriz[i][j]=0;
        }
    }
    int i, j, num, rango;
    rango = (rf - ri) + 1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < 4; j++)
        {
            do
            {
                num = (rand() % 16) + 1;
            } while (busqueda_secu_mat(matriz, m, num) != -1);
            matriz[i][j] = num;
        }
    }
}

void imp_vector(int vector[], int m) // listo
{
    int num = 0;
    printf("El vector es\n");
    for (int i = 0; i < m; i++) // mientras que i < que m este imprime lo que hay en vector
    {
        num += 1;
        printf("%d → %5d\n", num, vector[i]);
    }
}

void orden_vect(int vector[], int m) // listo
{
    int i,num=0;
    printf("Vector desacomodado");
    imp_vector(vector, 15); // vector desacomodado
    printf("Ordenado\n");
    for (i = 0; i < m; i++) // vector acomodado
    {
        num +=1;
        ordenar(vector, 15);
        printf("%d→%5d\n", num, vector[i]);
       
    }
}

void imp_matriz(int matriz[][4], int m) // listo
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}


//actividad 8 parte 2
void vector_alea(int vector[], int m, int ri, int rf) // listo
{
    int i, num, rango;
    rango = (rf - ri) + 1;
    for (i = 0; i < m; i++)
    {
        do
        {
            num = (rand() % 15000) + 1;// desde 1 a 15 mil
        } while (busqueda_secu(vector, i, num) != -1);
        vector[i] = num; // almacenamos datos validos
    }
}

int busqueda_secu(int vector[], int m, int val)
{
    for (int i = 0; i < m; i++)
    {
        if (vector[i] == val)
        {
            return i;
        }
    }
    return -1;
}

void buscar(int vector[], int m)
{
    int num, pos;
    num = validar(100, 200, "Que numero ocupas???\n");
    pos = busqueda_secu(vector, m, num);
    if (pos != -1)
    {
        printf("El valor existe esta en el indice %d\n", pos);
    }
    else
    {
        printf("Ese numero no existe\n");
    }
}
void ordenar(int vector[], int m)
{
    int i, j;
    int temp;
    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (vector[j] < vector[i])
            {
                temp = vector[j];
                vector[j] = vector[i];
                vector[i] = temp;
            }
        }
    }
}

int busqueda_secu_mat(int matriz[][4], int m, int val)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            if (matriz[i][j] == val)
            {
                return i;
            }
        }
    }
    return -1;
}

void burbuja(int *vector, int m)
{
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - i; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                swichea(&vector[j], &vector[j + 1]);
            }
        }
    }
}

void swichea(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void seleccion(int vect[], int m)
{
    for (int i = 0; i < m - 1; i++)
    {
        int menor, temp = i;
        for (int j = i + 1; j < m; j++)
        {
            if (vect[j] < vect[menor])
            {
                menor = j;
            }
        }
        if (menor != i)
        {
            temp = vect[i];
            vect[i] = vect[menor];
            vect[menor] = temp;
        }
    }
}
void quicksort(int vector[], int ri, int rf) // revisar reloj se cicla por cada numero
{
    int i, j, mitad, temp;
    i = ri;
    j = rf;
    mitad = vector[(ri + rf) / 2];

    do
    {

        while (vector[i] < mitad) // avanza al valor inicial
            i++;
        while (vector[j] > mitad) // avanza al valor final
            j--;
        if (i <= j)
        {
            temp = vector[i];
            vector[i] = vector[j];
            vector[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (ri < j)
    {
        quicksort(vector, ri, j); // Ordenamos la primera mitad
    }
    if (i < rf)
    {

        quicksort(vector, i, rf); // Ordenamos la segunda mitad
    }
}

void shellSort(int vector[], int m)
{
    int distancia;
    for (distancia = m / 2; distancia > 0; distancia /= 2) // divide la distancia entre dos cada que se ejecuta
    {
        for (int i = distancia; i < m; i++) // recorre todo iniciando con el tamaño de la distancia
        {
            int temp = vector[i];
            int j = i;
            while (j >= distancia && vector[j - distancia] > temp) // manda lo mas grande al final
            {
                vector[j] = vector[j - distancia]; // mueve los numeros de lugar
                j -= distancia;
            }
            vector[j] = temp; // pone el num donde debe de ir acomodado
        }
    }
}

void mergesort_1(int vector[], int izqui, int medio, int dere)
{
    int i, j, k, tam1, tam2;
    tam1 = medio - izqui + 1;
    tam2 = dere - medio;
    int iz[tam1];
    int der[tam2]; // vectores nuevos para esta duncion
    // Copiamos los datos a los vectores nuevos
    for (i = 0; i < tam1; i++)
    {
        iz[i] = vector[izqui + i];
    }
    for (j = 0; j < tam2; j++)
    {
        der[j] = vector[medio + 1 + j];
    }
    i = 0;
    j = 0;
    k = izqui; // juntamos i y j en k
    while (i < tam1 && j < tam2)
    {
        if (iz[i] <= der[j])
        {
            vector[k] = iz[i];
            i++;
        }
        else
        {
            vector[k] = der[j];
            j++;
        }
        k++;
    }

    while (i < tam1) // pasamos lo que qeude en iz
    {
        vector[k] = iz[i];
        i++;
        k++;
    }

    while (j < tam2) // pasar  los datos que quedan en  der
    {
        vector[k] = der[j];
        j++;
        k++;
    }
}

void mergesort_2(int vector[], int izqui, int dere)
{

    if (izqui < dere)
    {

        int medio = izqui + (dere - izqui) / 2;

        mergesort_2(vector, izqui, medio); // Ordenamos la primera mitad

        mergesort_2(vector, medio + 1, dere); // Ordenamos la segunda mitad

        mergesort_1(vector, izqui, medio, dere); // Combinamos las dos mitades ordenadas
    }
}

void busqueda_secuencial(int vector[], int m)
{
    int num, pos;
    num = validar(1, 15000, "Que numero ocupas???\n");
    pos = busqueda_secu(vector, m, num);
    if (pos != -1)
    {
        printf("El valor existe esta en el indice %d\n", pos);
    }
    else
    {
        printf("El valor no existe\n");
    }
}

int busqueda_bin(int *vector, int m)
{
    int num,ri=0,rf=m-1;
    num = validar(1, 15000, "Que numero buscas?\n");
    while (ri <= rf)
    {
        int pos = ri +  ( (rf - ri) / 2);
        if (vector[pos] == num)
        {
            printf("El valor existe y está en el índice %d\n", pos);
            return pos;
        }
        if (vector[pos] > num)
        {
            rf = pos - 1;
        }
        else
        {
            ri = pos + 1;
        }
    }
    printf("El valor no existe\n");
    return -1;
}

/*MMMMWXkoldddxxxddoox0NMMMMMM       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMNOool''xWMMMMW0;.cookXMMMM       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMW0llONWk',OWMMMKc.oNW0olkNMM       MMMMWX0KK00KKKKKKKKKK00KKKXWMMM
MWk,:KMMMWx';0MMXl.lXMMMNo'oNM       MMMXOO0O0OKWWWWWWWWWW0O0O0OOXMM
MO:..oNMMMNd.:O0l.cXMMMWk'.,xW       MMNk0MN0K00WMMMMMMMMW0KKKWWOkWM
Nolk:.oNMMMNo....:KMMMWk,,xocK       MMKkXMW00KOXMMMMWMMMKOXO0MMKkXM
XcoNK:.oNMMMXo;;l0MMMWk',kWkc0       MMKOXMW0kX00WMMMMMMNOKXkKMMKkXM
XloNWK:.dNMWx,..'dNMWk',kWWxc0       MMKOXMM0dKNO0WMMMMWOON0dKMMKkXM
WxcOWMK:'dXk,,dx:'xNk',kWMXloN       MMXOXMMKdkNNKXWWWNXKNXxdXMMKkXM
MNoc0WMK:':,'kWMK:':',kWMXolKM       MMNk0MMXdd0KKKKKKKKKKOoxNMW0ONM
MMNdcxNWK:..xWMMM0;.,kWWOloKMM       MMNO0WMNxcdoxXWWWWKxoockWMNO0WM
MMMW0olx0OoxNMMMMWOlkKkooONMMM       MMWX0KNNk::oKMMMMMW0l:cOWNK0XMM
MMMMMWKkdddxkkOOkkxdddx0NMMMMM       MMMWNKKKOkxk000000K0kxk0K0KNMMM
MMMMMMMMWXOdollllldkKWMMMMMMM        MMMMMMMMWWWWWWWNNWWWWWWMMMMMMM*/

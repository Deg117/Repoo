/*Brian De Jesus Gatelum Fierro
Matricula:373408
Actividad 9
24/03/2025
BGF_ACT9_PE_.CPP
*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

typedef struct _talum
{
    int status; // 1 activo 0 inactivo
    int matri;
    char nombre[50];
    char apperno[30];
    char apmaterno[30];
    int edad;
    int sexo; // 1 para H 2 para mujer
} Ts_alum;
// nueva libreria para esta actividad ya que la otra estab demaciado desordenada
// y con funciones no necesarias en esta actividad
int validar(int ri, int rf, const char *msge);
char *my_gets(char *cadena, int tamano);
void mayus(char texto[]);
int solo_letras(char texto[]);
void opciones();
void elimina_reg(Ts_alum vect[], int m);
Ts_alum agregar_manu(Ts_alum vector[]);
Ts_alum agregar_aleato(Ts_alum vector[]);
void imp_vect_reg(Ts_alum vector[], int m);
void burbuja(Ts_alum *vector, int m);
void swichea(int *num1, int *num2);
void seleccion(Ts_alum vect[], int m);
void busqueda_secuencial(Ts_alum vector[], int m);
int busqueda_sec(Ts_alum vector[], int m, int val);
int busqueda_bin(Ts_alum vector[], int m);
void insercion(Ts_alum vect[], int m);
int no_repetidos(Ts_alum vec[], int m, int matricula);
int ordenado = 0;

void opciones()
{
    Ts_alum reg;
    Ts_alum vector;
    Ts_alum vector_reg[2500];
    int op, opc;
    int j = 0;
    int band = 0;
    int llena = 0; // la uso para lleavr orden en ordenamiento
    do
    {
        printf("1.-Agregar automaticamente\n");
        printf("2.-Agregar manual\n");
        printf("3.-Eliminar registro\n");
        printf("4.-Buscar\n");
        printf("5.-Ordenar\n");
        printf("6.-Imprimir\n");
        printf("0.-Salir\n");
        op = validar(0, 6, "Dame una opcion\n");
        switch (op)
        {
        case 1:
            for (int i = 0; i < 10; i++)
            {
                reg = agregar_aleato(vector_reg);
                vector_reg[j++] = reg;
            }
            printf("Todo bien\n"); // para que sepa que se agregaron bien
            band = 1;
            llena = 1;
            ordenado = 0;
            break;
        case 2:
            do
            {
                reg = agregar_manu(vector_reg);
                vector_reg[j++] = reg;
                opc = validar(0, 1, "Quieres continuar agregando?\n(1 para si, 0 para no)\n");
            } while (opc != 0);
            band = 1;
            llena = 1;
            ordenado = 0;
            break;
        case 3:
            if (band)
            {
                do
                {
                    elimina_reg(vector_reg, j);
                    opc = validar(0, 1, "Quieres continuar borrando? \n(1 para si, 0 para no)\n");
                } while (opc != 0);
            }
            else
            {
                printf("Agrega alumnos primero si no que eliminas?\n"); // recordatorio de que esta vacio
            }
            break;
        case 4:
            if (llena == 0)
            {
                printf("Agrega algo si no que buscas...\n"); // otro mensajito
            }
            else
            {
                if (ordenado == 0)
                {
                    printf("Busqueda secuencial\n:");
                    busqueda_secuencial(vector_reg, j);
                }
                else
                {
                    printf("Busqueda Binaria\n:");
                    busqueda_bin(vector_reg, j);
                }
            }
            break;
        case 5:
            if (llena == 0)
            {
                printf("Agrega algo si no que ordenas...\n"); // mensajito amable
            }
            else
            {
                if (ordenado == 0)
                {
                    if (j <= 10)
                    {
                        burbuja(vector_reg, j);
                        printf("Se uso el metodo de burbuja\n");
                    }
                    if (j > 10 && j < 20)
                    {
                        seleccion(vector_reg, j);
                        printf("se utilizo el metodo de seleccion\n");
                    }
                    if (j >= 20)
                    {
                        insercion(vector_reg, j);
                        printf("se utilizo el metodo de insercion\n");
                    }
                }
                else
                {
                    printf("Ya se ordeno no te lo puedo ordenar mas\n"); // por si no agrego mas datos y quiere seguir ordenando
                }
                ordenado = 1;
            }
            break;
        case 6:
            if (band)
            {
                imp_vect_reg(vector_reg, j);
            }
            else
            {
                printf("Agrega alumnos primero si no que te muestro...\n");
            }
            break;
        case 0:
            printf("saliendo\n");
            break;
        default:
            break;
        }
    } while (op != 0);
}

Ts_alum agregar_aleato(Ts_alum vector[]) // reiniciar el ciclo cada que se llame
{
    Ts_alum reg;
    int j = 0;

    if (j >= 2500) // Verificar que no exceda el tamaño del vector
    {
        printf("Vector lleno\n");
    }
    char nomh[10][10] = {"CHABELO", "BRIAN", "WILLIAM", "KEVIN", "ANGEL", "ISIDRO", "JORGE", "JOSE", "MARIO", "ERICK"};
    char nomm[10][10] = {"SOFIA", "ALMA", "VICTORIA", "KARLA", "IVANA", "NELLY", "KIYUMI", "TANYA", "DAYANA", "CLAUDIA"};
    char ape[10][10] = {"GASTELUM", "GOZA", "BAEZ", "MARCELA", "OBRADOR", "ZAZUETA", "CARRERA", "FELIX", "SHEINBAUM", "NEVAREZ"};
    int sex[2] = {1, 2};
    reg.status = 1;
    reg.matri = (rand() % 99999) + 300000;
    while (no_repetidos(vector, 2500, reg.matri))
    {
        reg.matri = (rand() % 99999) + 300000;
    }
    strcpy(reg.apperno, ape[rand() % 10]);
    strcpy(reg.apmaterno, ape[rand() % 10]);

    if ((rand() % 2) == 0)
    {
        strcpy(reg.nombre, nomh[rand() % 10]);
        reg.sexo = 1; // Hombre
    }
    else
    {
        strcpy(reg.nombre, nomm[rand() % 10]);
        reg.sexo = 2; // Mujer
    }

    reg.edad = (rand() % 82) + 18;

    (j)++;
    return reg;
}

Ts_alum agregar_manu(Ts_alum vector[])
{
    Ts_alum reg;
    reg.status = 1;

    reg.matri = validar(300000, 399999, "Matricula\n");
    while (no_repetidos(vector, 2500, reg.matri))
    {
        printf("Dame una matricula que no exista por favor\n:");
        reg.matri = validar(300000, 399999, "Matricula\n");
    }
    
    printf("Nombre\n");
    my_gets(reg.nombre, 50);
    mayus(reg.nombre);

    while (!solo_letras(reg.nombre))
    {

        printf("Solo se permiten letras \n.Dame un nombre valido\n");
        my_gets(reg.nombre, 50);
        mayus(reg.nombre);
    }
    printf("Apellido paterno\n");
    my_gets(reg.apperno, 30);
    mayus(reg.apperno);
    while (!solo_letras(reg.apperno))
    {
        printf("Solo se permiten letras \n Dame un apellido valido\n");
        my_gets(reg.apperno, 30);
        mayus(reg.apperno);
    }
    printf("Apellido materno\n");
    my_gets(reg.apmaterno, 30);
    mayus(reg.apmaterno);
    while (!solo_letras(reg.apmaterno))
    {
        printf("Solo se permiten letras \nDame un apellido valido\n");
        my_gets(reg.apmaterno, 30);
        mayus(reg.apmaterno);
    }
    printf("Sexo\n");
    reg.sexo = validar(1, 2, "Dame 1 para Hombre o 2 para Mujer\n");
    reg.edad = validar(10, 90, "Dame te edad\n");
    return reg;
}

void imp_vect_reg(Ts_alum vector[], int m) // acomodar impresion
{
    char sex[30];
    printf("\nNo|   STATUS|  MATRICULA|   NOMBRE      |   APPAT       |   APMAT       |    EDAD|   SEXO  |\n");
    for (int i = 0; i < m; i++)
    {
        if (vector[i].status == 1)
        {
            if (vector[i].sexo == 1)
            {
                strcpy(sex, "Hombre");
            }
            else
            {
                strcpy(sex, "Mujer");
            }
            printf("%2d|   %6d|   %8d|   %-12s|   %-12s|   %-12s|   %5d|   %6s|\n",
                   i, vector[i].status, vector[i].matri, vector[i].nombre,
                   vector[i].apperno, vector[i].apmaterno, vector[i].edad, sex);
        }
    }
    printf("\n");
}

char *my_gets(char *cadena, int tamano)
{
    size_t longitud;
    fflush(stdin);
    fgets(cadena, 254, stdin);
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

int  validar(int ri, int rf, const char *msge)
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

void  mayus(char texto[])
{
    int i;
    for (i = 0; i < texto[i] != '\0'; i++)
    {
        if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            texto[i] = texto[i] - 32;
        }
    }
}

int solo_letras(char texto[])
{
    int i = 0;
    while (texto[i] != '\0')
    {
        if (!isalpha(texto[i]) && texto[i] != ' ')
        {
            return 0; // tiene numeros o algo que no son letras
        }
        i++;
    }
    return 1; // dato valido
}

int busqueda_bin(Ts_alum vector[], int m)
{
    int num, ri = 0, rf = m - 1;
    num = validar(300000, 399999, "Que Matricula buscas?\n");
    while (ri <= rf)
    {
        int pos = ri + ((rf - ri) / 2);
        if (vector[pos].matri == num)
        {
            printf("La matricula existe y esta en el indice %d\n", pos);
            return pos;
        }
        if (vector[pos].matri > num)
        {
            rf = pos - 1;
        }
        else
        {
            ri = pos + 1;
        }
    }
    printf("La matricula no existe\n");
    return -1;
}

void busqueda_secuencial(Ts_alum vector[], int m)
{
    int num, pos;
    num = validar(300000, 399999, "Que Matricula ocupas???\n");
    pos = busqueda_sec(vector, m, num);

    if (pos != -1)
    {
        printf("La Matricula existe y esta en el indice %d\n", pos);
    }
    else
    {
        printf("La Matricula no existe\n");
    }
}

int busqueda_sec(Ts_alum vector[], int m, int val)
{
    for (int i = 0; i < m; i++)
    {
        if (vector[i].matri == val)
        {
            return i;
        }
    }
    return -1;
}

void elimina_reg(Ts_alum vector[], int m)
{
    int matri;
    matri = validar(300000, 399999, "Que matricula vas a borrar?...\n");
    for (int i = 0; i < m; i++)
    {
        if (vector[i].status == 1 && vector[i].matri == matri) // busca que si este el alumno
        {
            vector[i].status = 0; // cambia el status para no volverlo a mostrar
            printf("La Matricula se elimino\n");
            return;
        }
    }
    printf("Matricula no encontrada \n");
}

void burbuja(Ts_alum *vector, int m)
{
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - i; j++)
        {
            if (vector[j].matri > vector[j + 1].matri)
            {
                swichea(&vector[j].matri, &vector[j + 1].matri);
            }
        }
    }
}

void swichea(int *num1, int *num2) // hace los cambios aca y los regresa a burbuja
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void seleccion(Ts_alum vect[], int m)
{
    for (int i = 0; i < m - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < m; j++)
        {
            if (vect[j].matri < vect[menor].matri) // revisa la matricula actual si se cumple se cambia la que era menor
            {
                menor = j;
            }
        }
        if (menor != i)
        {
            Ts_alum temp = vect[i];
            vect[i] = vect[menor];
            vect[menor] = temp;
        }
    }
}

void insercion(Ts_alum vect[], int m)
{
    int i, j;

    Ts_alum matri;
    for (i = 1; i < m; i++)
    {
        matri = vect[i]; // agarra la siguiente matricula
        j = i - 1;
        while (j >= 0 && vect[j].matri > matri.matri)
        {
            vect[j + 1] = vect[j]; // Mueve de lugar el dato
            j = j - 1;
        }
        vect[j + 1] = matri;
    }
}

int no_repetidos(Ts_alum vector[], int m, int matricula)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (vector[j].matri == matricula)
            {
                return 1;
            }
        }
    }
    return 0;
}
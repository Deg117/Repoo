#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct _talum
{
    int status; // 1 activo 0 inactivo
    int matri;
    int gen; // 1 macho 2 hembra
    char mascota[20];
    char tipo[20];
    char nombre[50];
    char apperno[30];
    char apmaterno[30];
    char telefono[10];
    int edad;
    int sexo; // 1 para H 2 para mujer
} Ts_alum;
const char tipo1[10][10] = {"PERRO", "GATO", "CUYO", "PATO", "CONEJO", "TORTUGA", "URON", "IGUANA", "PERICO", "CABALLO"};

// nueva libreria para esta actividad ya que la otra estaba demaciado desordenada
// y con funciones no necesarias en esta actividad
void generar_arch(Ts_alum vector[], int m, char *narchivo);
int leer_arch(Ts_alum vector[], int m, char *narchivo);
void eliminados(Ts_alum vector[], int m);
void generar_archbin(Ts_alum vector[], int m, char *narchivo);
void modificar(Ts_alum vector[], int m);
int busqueda_secuencial_2(Ts_alum vector[], int m);
int busqueda_secuencial_3(Ts_alum vector[], int m);
void agregartxt(char *narchivo);
void agregartmp(char *narchivo);
int leer_archbin(Ts_alum vector[], int m, char *narchivo);

int validar(int ri, int rf, const char *msge);
char *my_gets(char *cadena, int tamano);
void mayus(char texto[]);
int solo_letras(char texto[]);
void opciones();
void elimina_reg(Ts_alum vect[], int m);
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
Ts_alum vector_reg[50000];
int cargar = 0;
int cargabin=0;
void opciones()
{
    char narchivo[50];
    Ts_alum reg;
    Ts_alum vector;
    //   Ts_alum vector_reg[50000];
    int op, opc;
    int ordenado = 0;
    int j = 0;
    int arch = 0;
    int band = 0;
    int elim = 0;
    int llena = 0; // la uso para lleavr orden en ordenamiento
    do
    {
        printf("1 Agregar \n");
        printf("2 Editar registro\n");
        printf("3 Eliminar \n");
        printf("4 Buscar\n");
        printf("5 Ordenar\n");
        printf("6 Mostrar\n");
        printf("7 generar archivo de texto\n");
        printf("8 Ver archivo de texto\n");
        printf("9 Crear archivo binario\n");
        printf("10 cargar archivo binario\n");
        printf("11 Mostrar borrados\n");
        printf("0.-Salir\n");
        op = validar(0, 11, "Dame una opcion\n");
        switch (op)
        {
        case 1:
            for (int i = 0; i < 100; i++)
            {
                reg = agregar_aleato(vector_reg);
                vector_reg[j++] = reg;
            }
            printf("Todo bien\n"); // para que sepa que se agregaron bien
            system("PAUSE");
            system("CLS");
            band = 1;
            llena = 1;
            ordenado = 0;

            break;
        case 2:
            if (band)
            {
                modificar(vector_reg, j);
                system("PAUSE");
                system("CLS");
            }
            else
            {
                printf("Agrega animales primero, si no que te modifico rey?\n");
                system("PAUSE");
                system("CLS");
            }

            break;
        case 3:
            if (band)
            {
                do
                {
                    elimina_reg(vector_reg, j);
                    opc = validar(0, 1, "Quieres continuar borrando? \n(1 para si, 0 para no)\n");
                    elim = 1;
                    system("CLS");
                } while (opc != 0);
            }
            else
            {
                printf("Agrega alumnos primero si no que eliminas?\n"); // recordatorio de que esta vacio
                system("PAUSE");
                system("CLS");
            }

            break;
        case 4:
            if (llena == 0)
            {
                printf("Agrega algo si no que buscas...\n"); // otro mensajito
                system("PAUSE");
                system("CLS");
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
                system("PAUSE");
                system("CLS");
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
                    system("PAUSE");
                    system("CLS");
                }
                ordenado = 1;
            }
            break;
        case 6:
            if (band)
            {
                imp_vect_reg(vector_reg, j);
                system("PAUSE");
                system("CLS");
            }
            else
            {
                printf("Agrega alumnos primero si no que te muestro...\n");
                system("PAUSE");
                system("CLS");
            }
            break;
        case 7:
            if (band)
            {
                printf("Dime como vas a nombrar el archivo\n");
                my_gets(narchivo, 50);
                agregartxt(narchivo);
                generar_arch(vector_reg, j, narchivo);
                system("CLS");
                printf("Todo chido\n");
                arch = 1;
            }
            else
            {
                printf("agrega alumnos si no el archivo estara en blanco\n"); // recordatorio de que esta vacio
            }
            break;
        case 8:
            if (cargar != 1)
            {
                printf("Dime que archivo quieres leer solo puedo cargar 1 por ejecucion del programa\n");
                my_gets(narchivo, 50);
                agregartxt(narchivo);
                j = leer_arch(vector_reg, j, narchivo);
                cargar = 1;
            }
            else
            {
                printf("Ya lo cargue una vez ya no puedo otra\n");
                system("PAUSE");
                system("CLS");
            }
            if (j > 0)
            {
                band = 1;
                llena = 1;
            }
            break;
        case 9:
            if (band)
            {
                printf("Dime como vas a nombrar el archivo\n");
                my_gets(narchivo, 50);
                agregartmp(narchivo);
                generar_archbin(vector_reg, j, narchivo);
                system("PAUSE");
                system("CLS");
            }
            else
            {
                printf("Agrega unos registros primero\n");
                system("PAUSE");
                system("CLS");
            }

            break;

        case 10:
        if (cargabin != 1)
        {
            printf("Dime que archivo quieres leer solo puedo cargar 1 por ejecucion del programa\n");
            my_gets(narchivo, 50);
            agregartmp(narchivo);
           j = leer_archbin(vector_reg, j, narchivo);
            cargabin = 1;
        }
        else
        {
            printf("Ya lo cargue una vez ya no puedo otra\n");
            system("PAUSE");
            system("CLS");
        }
            break;
        case 11:
            if (elim)
            {
                eliminados(vector_reg, j);
                system("PAUSE");
                system("CLS");
            }
            else
            {
                printf("Elimina alumnos si no que te muestro?\n"); // recordatorio de que esta vacio
                system("PAUSE");
                system("CLS");
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

    if (j >= 50000) // Verificar que no exceda el tamaño del vector
    {
        printf("Vector lleno\n");
    }
    char telefono[10];
    char macho[10][10] = {"DOBI", "FRED", "ROCKY", "ZEUS", "REX", "PORFIRIO", "BARTOLO", "TOBY", "TIP_TIP", "NEGRO"};
    char hembra[10][10] = {"LOLA", "PUPI", "MELONA", "FRIDA", "NEGRA", "BLANCA", "SOTA", "MIRRU", "REINA", "BELLA"};
    char tipo[10][10] = {"PERRO", "GATO", "CUYO", "PATO", "CONEJO", "TORTUGA", "URON", "IGUANA", "PERICO", "CABALLO"};
    char nomh[10][10] = {"CHABELO", "BRIAN", "WILLIAM", "KEVIN", "ANGEL", "ISIDRO", "JORGE", "JOSE", "MARIO", "ERICK"};
    char nomm[10][10] = {"SOFIA", "ALMA", "VICTORIA", "KARLA", "IVANA", "NELLY", "KIYUMI", "TANYA", "DAYANA", "CLAUDIA"};
    char ape[10][10] = {"GASTELUM", "GOZA", "BAEZ", "MARCELA", "OBRADOR", "ZAZUETA", "CARRERA", "FELIX", "SHEINBAUM", "NEVAREZ"};
    int sex[2] = {1, 2};
    reg.status = 1;
    reg.matri = (rand() % 99999) + 300000;
    strcpy(reg.tipo, tipo[rand() % 10]);
    for (int i = 0; i < 10; i++)
    {
        telefono[i] = (rand() % 10) + '0'; // el +0 es para coventir a letra
    }
    telefono[10] = '\0';
    strcpy(reg.telefono, telefono);

    if ((rand() % 2) == 0)
    {
        strcpy(reg.mascota, macho[rand() % 10]);
        reg.gen = 1; // macho
    }
    else
    {
        strcpy(reg.mascota, hembra[rand() % 10]);
        reg.gen = 2; // hembra
    }

    while (no_repetidos(vector, 50000, reg.matri))
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

    (j)++;
    return reg;
}

void imp_vect_reg(Ts_alum vector[], int m) // acomodar impresion
{
    int j = 0;
    char sex[30];
    printf("\n|STATUS| MATRICULA| NOMBRE  |  TIPO       | GENERO |        PROPIETARIO               | NO. TELEFONO\n");
    for (int i = 0; i < m; i++)
    {
        if (vector[i].status == 1)
        {
            if (vector[i].gen == 1)
            {
                strcpy(sex, "MACHO");
            }
            else
            {
                strcpy(sex, "HEMBRA");
            }
            printf("|%3d   |   %7d| %-8s|  %-8s   | %6s | %-10s  %-10s %-10s| %10s\n",
                   vector[i].status, vector[i].matri, vector[i].mascota, vector[i].tipo, sex, vector[i].nombre,
                   vector[i].apperno, vector[i].apmaterno, vector[i].telefono);
            j++;
            if (j == 40)
            {
                j=0;
                system("PAUSE");
            }
        }
        printf("\n");
    }
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

void mayus(char texto[])
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
    matri = validar(300000, 399999, "Que matricula vas a borrar?\n");
    int posi = busqueda_secuencial_3(vector, m);
    int res;
    if (posi != -1)
    {
        printf("DATOS DEL ANIMAL\n");
        printf("Matricula: %d\n", vector[posi].matri);
        printf("Nombre de mascota: %s\n", vector[posi].mascota);
        printf("Tipo: %s\n", vector[posi].tipo);
        printf("Genero: %d\n", vector[posi].gen);
        printf("Propietario: %s %s %s\n", vector[posi].nombre, vector[posi].apperno, vector[posi].apmaterno);
        printf("No. de telefono: %s\n", vector[posi].telefono);

        res = validar(1, 2, "Seguro quieres eliminarlo?  1 para si 2 para no\n");

        if (res == 1)
        {
            for (int i = 0; i < m; i++)
            {
                if (vector[i].status == 1 && vector[i].matri == matri)
                {
                    vector[i].status = 0;
                    printf("La matricula %d se elimino\n", matri);
                    return;
                }
            }
        }
        else
        {
            printf("Se cancela \n");
        }
    }
    else
    {
        printf("La matricula no existe.\n");
    }
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
/************************************************************* */
void swichea(int *num1, int *num2) // hace los cambios aca y los regresa a burbuja
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
/*********************************************************** */
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
/******************************************************* */
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
/****************************************************** */
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
/****************************************************** */

/*************************************************** */

void modificar(Ts_alum vector[], int m)
{
    int opc;
    int posi = busqueda_secuencial_2(vector, m);
    if (posi != -1)
    {
        printf("DATOS DEL ANIMAL\n");
        printf("Matricula: %d\n", vector[posi].matri);
        printf("Nombre de mascota:%s\n", vector[posi].mascota);
        printf("Tipo: %s\n", vector[posi].tipo);
        printf("Genero:%d\n", vector[posi].gen);
        printf("Propietario: %s %s %s \n", vector[posi].nombre, vector[posi].apperno, vector[posi].apmaterno);
        printf("No. de telefono: %s\n", vector[posi].telefono);
        do
        {
            printf("1-Nombre Propietario \n");
            printf("2-Apellido paterno Propietario\n");
            printf("3-Apellido materno Propietario\n");
            printf("4-Tipo de animal\n");
            printf("5-Nombre de mascota\n");
            printf("6-Genero de mascota\n");
            printf("7-No. Telefono\n");
            printf("8-Ya nada\n");
            opc = validar(1, 8, "Que quieres modificar?\n");
            system("CLS");

            switch (opc)
            {
            case 1:
                printf("Nuevo nombre:\n");
                my_gets(vector[posi].nombre, 30);
                mayus(vector[posi].nombre);
                break;
            case 2:
                printf("Nuevo apellido paterno:\n");
                my_gets(vector[posi].apperno, 30);
                mayus(vector[posi].apperno);
                break;
            case 3:
                printf("Nuevo apellido materno:\n");
                my_gets(vector[posi].apmaterno, 30);
                mayus(vector[posi].apmaterno);
                break;
            case 4:
                printf("Cual es el animal\n");
                for (int i = 0; i < 10; i++)
                {
                    printf("%d-%s\n", i, tipo1[i]);
                }
                strcpy(vector[posi].tipo, tipo1[validar(0, 9, "Elige una opcion: ")]);

                break;
            case 5:
                printf("Nuevo nombre de mascota:\n");
                my_gets(vector[posi].mascota, 30);
                mayus(vector[posi].mascota);
                break;

            case 6:
                printf("Genero de mascota (1 macho, hembra):\n");
                vector[posi].gen = validar(1, 2, "Selecciona el genero: ");
                break;
            case 7:
                printf("Nuevo telefono:\n");
                my_gets(vector[posi].telefono, 15);
                break;
            case 8:
                printf("Terminaste de modificar.\n");
                break;
            }
        } while (opc != 8);
    }
}

int busqueda_secuencial_2(Ts_alum vector[], int m) // uso esta para buscar en la modificacion de datos
{
    int num, pos;
    num = validar(300000, 399999, "Quieres modificar, Dame la matricula\n");
    pos = busqueda_sec(vector, m, num);

    if (pos != -1)
    {
        printf("La Matricula existe,desplegando opciones\n");
    }
    else
    {
        printf("La Matricula no existe\n");
    }

    return pos;
}

int busqueda_secuencial_3(Ts_alum vector[], int m) // uso esta para buscar en la modificacion de datos
{
    int num, pos;
    pos = busqueda_sec(vector, m, num);

    if (pos != -1)
    {
        printf("La Matricula existe,desplegando opciones\n");
    }
    else
    {
        printf("La Matricula no existe\n");
    }

    return pos;
}

void generar_archbin(Ts_alum vector[], int m, char *narchivo)
{
    FILE *fb;
    fb = fopen(narchivo, "wb");
    //------------------------------------------------------------------------
    if (fb == NULL)
    {
        printf("Error al abrir el archivo.\n"); // si el programa falla al abrir un nuevo archivo regresamos un mensaje y evitamos que crashee
        return;
    }

    for (int i = 0; i < m; i++)
    {
        if (vector[i].status == 1)
        {
            fwrite(&vector[i], sizeof(Ts_alum), 1, fb);
        }
    }

    fclose(fb);
    printf("Todo bien\n");
}

void generar_arch(Ts_alum vector[], int m, char *narchivo)
{
    FILE *fa;
    fa = fopen(narchivo, "w");
    //------------------------------------------------------------------------
    if (fa == NULL)
    {
        printf("Error al abrir el archivo.\n"); // si el programa falla al abrir un nuevo archivo regresamos un mensaje y evitamos que crashee
        return;
    }
    printf("|STATUS| MATRICULA| NOMBRE  |  TIPO       | GENERO |        PROPIETARIO               | NO. TELEFONO\n");
    for (int i = 0; i < m; i++)
    {
        if (vector[i].status == 1)
        {
            fprintf(fa, "%3d       %7d  %-8s   %-8s     %6d   %-10s   %-10s  %-10s  %10s\n",
                    vector[i].status, vector[i].matri, vector[i].mascota, vector[i].tipo, vector[i].gen, vector[i].nombre,
                    vector[i].apperno, vector[i].apmaterno, vector[i].telefono);
        }
    }
    printf("\n");
    //--------------------------------------------------------------------------------
    fclose(fa);
}
//************************************************** */
int leer_arch(Ts_alum vector[], int m, char *narchivo)
{
    int i = m;
    FILE *fa = fopen(narchivo, "r");

    if (!fa)
    {
        printf("No se cargó el archivo\n");
        system("pause");
        return i;
    }

    printf("|STATUS| MATRICULA| NOMBRE  |  TIPO       | GENERO |        PROPIETARIO               | NO. TELEFONO\n");

    while (fscanf(fa, "%d %d %s %s %d %s %s %s %s",
                  &vector[i].status,
                  &vector[i].matri,
                  vector[i].mascota,
                  vector[i].tipo,
                  &vector[i].gen,
                  vector[i].nombre,
                  vector[i].apperno,
                  vector[i].apmaterno,
                  vector[i].telefono) == 9)
    {
        printf("|%3d      %7d %-8s  %-8s    %6d  %-10s  %-10s %-10s %10s\n",
               vector[i].status, vector[i].matri, vector[i].mascota, vector[i].tipo,
               vector[i].gen, vector[i].nombre, vector[i].apperno, vector[i].apmaterno,
               vector[i].telefono);
        i++;
    }

    fclose(fa);
    return i;
}

/*************************************************** */
void eliminados(Ts_alum vector[], int m)
{
    FILE *fb;
    fb = fopen("ELIMINADOS.tmp", "wb");
    if (fb == NULL)
    {
        printf("Error al abrir el archivo.\n"); // si el programa falla al abrir un nuevo archivo regresamos un mensaje y evitamos que crashee
        return;
    }
    printf("Animales Eliminados\n");
    fprintf(fb, "\n|STATUS| MATRICULA| NOMBRE  |  TIPO       | GENERO |        PROPIETARIO               | NO. TELEFONO\n");
    for (int i = 0; i < m; i++)
    {
        if (vector[i].status == 0)
        {
            fprintf(fb, "|%3d   |   %7d| %-8s|  %-8s   | %6d | %-10s  %-10s %-10s| %10s\n",
                    vector[i].status, vector[i].matri, vector[i].mascota, vector[i].tipo, vector[i].gen, vector[i].nombre,
                    vector[i].apperno, vector[i].apmaterno, vector[i].telefono);
        }
    }
    fclose(fb);
    printf("\n");
}

void agregartxt(char *narchivo)
{
    int i = 0;
    while (narchivo[i] != '\0')
        i++; // se va al final del narchivo
    narchivo[i++] = '.';
    narchivo[i++] = 't';
    narchivo[i++] = 'x';
    narchivo[i++] = 't';
    narchivo[i] = '\0';
}

void agregartmp(char *narchivo)
{
    int i = 0;
    while (narchivo[i] != '\0')
        i++; // se va al final del narchivo
    narchivo[i++] = '.';
    narchivo[i++] = 't';
    narchivo[i++] = 'm';
    narchivo[i++] = 'p';
    narchivo[i] = '\0';
}

int leer_archbin(Ts_alum vector[], int m, char *narchivo)
{
    int i = m;
    FILE *fa = fopen(narchivo, "rb");

    if (!fa)
    {
        printf("No se cargó el archivo\n");
        system("pause");
        return i;
    }

    printf("|STATUS| MATRICULA| NOMBRE  |  TIPO       | GENERO |        PROPIETARIO               | NO. TELEFONO\n");
    while (fread(&vector[i], sizeof(Ts_alum), 1, fa) == 1) {
        // Imprimir los datos del registro, ajusta según el formato de tu estructura
        printf("|%3d      %7d %-8s %-8s    %6d %-10s  %-10s %-10s %10s\n",
               vector[i].status, vector[i].matri, vector[i].mascota, vector[i].tipo,
               vector[i].gen, vector[i].nombre, vector[i].apperno, vector[i].apmaterno,
               vector[i].telefono);
        i++;
    }

    fclose(fa);
    return i;
}
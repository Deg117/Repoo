#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include <conio.h> // para getch()
int nivel_usu = 0; // global nivel usu
typedef int Tkey;
typedef struct usuarios
{
    int statu;
    char nomb[30];
    char contra[20];
    int nivel;
} Usu;

typedef struct _wrkr
{
    int status;
    Tkey enrollment; // Campo llave
    char name[30];
    char last_name_1[50];
    char last_name_2[50];
    char sex[15];
    char job_pstion[30];
    char state[30];
    int age;
    Tkey cell_phone;
} Twrkr;

void iniciar_sesion();
int leer_archbin2(Usu vector[], int m);
Usu agregar_usuario(Usu vector[], int m);
void leer_contrasena(char contrase[20], int m);
void generar_usuarios(Usu vector[], int m);

void generar_arch(Twrkr vector[], int m, char *narchivo);
void generar_archbin(Twrkr vector[], int m);
void agregartxt(char *narchivo);
void agregartmp(char *narchivo);
int leer_archbin(Twrkr vector[], int m);
int busqueda_secuencial_3(Twrkr vector[], int m);
int cargar_archbin(Twrkr vector[], int m);
void imp_vect_orde(Twrkr vector[], int m);
int inicializar();

int validar(int ri, int rf, const char *msge);
char *my_gets(char *cadena, int tamano);
void mayus(char texto[]);
int solo_letras(char texto[]);
void opciones();
void elimina_reg(Twrkr vect[], int m);
Twrkr agregar_aleato(Twrkr vector[]);
void imp_vect_reg(Twrkr vector[], int m);
void burbuja(Twrkr *vector, int m);
void swichea(int *num1, int *num2);
void seleccion(Twrkr vect[], int m);
void busqueda_secuencial(Twrkr vector[], int m);
int busqueda_sec(Twrkr vector[], int m, int val);
int busqueda_bin(Twrkr vector[], int m);
void insercion(Twrkr vect[], int m);
int no_repetidos(Twrkr vec[], int m, int matricula);

/****************************************************** */
Twrkr agregar_aleato(Twrkr vector[])
{

    Twrkr reg;
    char state[32][3] = {"AS", "BC", "BS", "CC", "CL", "CM", "CS", "CH", "DF", "DG",
                         "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC",
                         "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ",
                         "YN", "ZS"};
    char job[12][10] = {" DevSoft", "TrabSoc", "Traduct", "ProfPrim ", "IngRed", "AsistAdm",
                        "IngElec", "InvCien", "AnlSist", "IngCivil", "ChefEje", "AsServ"};
    int telefono[8];
    char nomh[10][10] = {"CHABELO", "BRIAN", "WILLIAM", "KEVIN", "ANGEL", "ISIDRO", "JORGE", "JOSE", "MARIO", "ERICK"};
    char nomm[10][10] = {"SOFIA", "ALMA", "VICTORIA", "KARLA", "IVANA", "NELLY", "KIYUMI", "TANYA", "DAYANA", "CLAUDIA"};
    char ape[10][10] = {"GASTELUM", "GOZA", "BAEZ", "MARCELA", "OBRADOR", "ZAZUETA", "CARRERA", "FELIX", "SHEINBAUM", "NEVAREZ"};
    int sex[2] = {1, 2};
    reg.status = 1;
    reg.enrollment = (rand() % 99999) + 300000;

    reg.cell_phone = 1000000 + rand() % 9000000; // num de telefono

    while (no_repetidos(vector, inicializar(), reg.enrollment)) // agregar bien el tamaño
    {
        reg.enrollment = (rand() % 99999) + 300000;
    }
    strcpy(reg.last_name_1, ape[rand() % 10]);
    strcpy(reg.last_name_2, ape[rand() % 10]);

    if ((rand() % 2) == 1)
    {
        strcpy(reg.name, nomh[rand() % 10]);
        strcpy(reg.sex, "HOMBRE");
    }
    else
    {
        strcpy(reg.name, nomm[rand() % 10]);
        strcpy(reg.sex, "MUJER");
    }
    reg.age = (rand() % 82) + 1;
    strcpy(reg.state, state[rand() % 32]);
    strcpy(reg.job_pstion, job[rand() % 12]);

    return reg;
}
/****************************************************** */
void imp_vect_reg(Twrkr vector[], int m)
{
    printf("\n| No | STATUS  | No.TRabajador |  NOMBRE     |    APPAT     |   APMAT     |  SEXO  | Posicion |stado|edad |No.Telefono\n");
    for (int i = 0; i < m; i++)
    {
        if (vector[i].status == 1)
        {
            printf("|%4d|  %3d    |   %10d  |  %-10s |  %-11s | %11s | %6s | %8s |  %s | %d  | %d\n",
                   i,
                   vector[i].status,
                   vector[i].enrollment,
                   vector[i].name,
                   vector[i].last_name_1,
                   vector[i].last_name_2,
                   vector[i].sex,
                   vector[i].job_pstion,
                   vector[i].state,
                   vector[i].age,
                   vector[i].cell_phone);
        }
    }
}
void imp_vect_orde(Twrkr vector[], int m)
{
    printf("\n| No | STATUS  | No.TRabajador |  NOMBRE     |    APPAT     |   APMAT     |  SEXO  | Posicion |stado|edad |No.Telefono\n");
    for (int i = 0; i < m; i++)
    {
        if (vector[i].status == 1)
        {
            printf("|%4d|  %3d    |   %10d  |  %-10s |  %-11s | %11s | %6s | %8s |  %s | %d  | %d\n",
                   i,
                   vector[i].status,
                   vector[i].enrollment,
                   vector[i].name,
                   vector[i].last_name_1,
                   vector[i].last_name_2,
                   vector[i].sex,
                   vector[i].job_pstion,
                   vector[i].state,
                   vector[i].age,
                   vector[i].cell_phone);
        }
    }
}
/****************************************************** */
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
/****************************************************** */
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
/****************************************************** */
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
/****************************************************** */
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
/****************************************************** */
int busqueda_bin(Twrkr vector[], int m)
{
    int num, ri = 0, rf = m - 1;
    num = validar(300000, 399999, "A quien buscas?\n");
    while (ri <= rf)
    {
        int pos = ri + ((rf - ri) / 2);
        if (vector[pos].enrollment == num)
        {
            printf("El trabajador existe y esta en el indice %d\n", pos);
            printf("\n| STATUS  | No.TRabajador |  NOMBRE     |    APPAT     |   APMAT     |  SEXO  | Posicion |stado|edad |No.Telefono\n");
            printf("|  %d      |   %10d  |  %-10s |  %-11s | %11s | %6s | %8s |  %s | %d  | %d\n",
                   vector[pos].status, vector[pos].enrollment, vector[pos].name, vector[pos].last_name_1,
                   vector[pos].last_name_2, vector[pos].sex, vector[pos].job_pstion, vector[pos].state,
                   vector[pos].age, vector[pos].cell_phone);
            return pos;
        }
        if (vector[pos].enrollment > num)
        {
            rf = pos - 1;
        }
        else
        {
            ri = pos + 1;
        }
    }
    printf("El trabajador no existe\n");
    return -1;
}
/****************************************************** */
void busqueda_secuencial(Twrkr vector[], int m)
{
    int num, pos;
    num = validar(300000, 399999, "Que trabajador ocupas???\n");
    pos = busqueda_sec(vector, m, num);
    if (pos != -1)
    {
        printf("El trabajador existe y esta en el indice %d\n", pos);
        printf("\n| STATUS  | No.TRabajador |  NOMBRE     |    APPAT     |   APMAT     |  SEXO  | Posicion |stado|edad |No.Telefono\n");
        printf("|  %d      |   %10d  |  %-10s |  %-11s | %11s | %6s | %8s |  %s | %d  | %d\n",
               vector[pos].status, vector[pos].enrollment, vector[pos].name, vector[pos].last_name_1,
               vector[pos].last_name_2, vector[pos].sex, vector[pos].job_pstion, vector[pos].state,
               vector[pos].age, vector[pos].cell_phone);
    }
    else
    {
        printf("El trabajador no existe\n");
    }
}
/****************************************************** */
int busqueda_sec(Twrkr vector[], int m, int val)
{
    for (int i = 0; i < m; i++)
    {
        if (vector[i].enrollment == val)
        {
            return i;
        }
    }
    return -1;
}
/****************************************************** */
void elimina_reg(Twrkr vector[], int m)
{
    int matri;
    matri = validar(300000, 399999, "Que trabajador vas a borrar?\n");
    int posi = busqueda_secuencial_3(vector, m);
    int res;
    if (posi != -1)
    {
        printf("DATOS DEL TRABAJADOR\n");
        printf("No.Trabajador: %d\n", vector[posi].enrollment);
        printf("Genero: %d\n", vector[posi].sex);
        printf("Trabajador: %s %s %s\n", vector[posi].name, vector[posi].last_name_1, vector[posi].last_name_2);
        printf("No. de telefono: %d\n", vector[posi].cell_phone);

        res = validar(1, 2, "Seguro quieres eliminarlo?  1 para si 2 para no\n");
        if (res == 1)
        {
            for (int i = 0; i < m; i++)
            {
                if (vector[i].status == 1 && vector[i].enrollment == matri)
                {
                    vector[i].status = 0;
                    printf("El trabajador %d se elimino\n", matri);
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
        printf("El trabajador no existe.\n");
    }
}
/****************************************************** */
void burbuja(Twrkr *vector, int m)
{
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - i; j++)
        {
            if (vector[j].enrollment > vector[j + 1].enrollment)
            {
                swichea(&vector[j].enrollment, &vector[j + 1].enrollment);
            }
        }
    }
}
/****************************************************** */
void swichea(int *num1, int *num2) // hace los cambios aca y los regresa a burbuja
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
/****************************************************** */
void seleccion(Twrkr vect[], int m)
{
    for (int i = 0; i < m - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < m; j++)
        {
            if (vect[j].enrollment < vect[menor].enrollment) // revisa la matricula actual si se cumple se cambia la que era menor
            {
                menor = j;
            }
        }
        if (menor != i)
        {
            Twrkr temp = vect[i];
            vect[i] = vect[menor];
            vect[menor] = temp;
        }
    }
}
/****************************************************** */
void insercion(Twrkr vect[], int m)
{
    int i, j;
    Twrkr trabajador;
    for (i = 1; i < m; i++)
    {
        trabajador = vect[i]; // agarra la siguiente matricula
        j = i - 1;
        while (j >= 0 && vect[j].enrollment > trabajador.enrollment)
        {
            vect[j + 1] = vect[j]; // Mueve de lugar el dato
            j = j - 1;
        }
        vect[j + 1] = trabajador;
    }
}
/****************************************************** */
int no_repetidos(Twrkr vector[], int m, int matricula)
{
    for (int i = 0; i < m; i++)
    {
        if (vector[i].enrollment == matricula)
        {
            return 1; // Ya existe
        }
    }
    return 0; // No existe
}
/****************************************************** */
void generar_archbin(Twrkr vector[], int m)
{
    FILE *fb;
    fb = fopen("datos.dat", "wb");
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
            fwrite(&vector[i], sizeof(Twrkr), 1, fb);
        }
    }

    fclose(fb);
    printf("Todo bien\n");
}
/****************************************************** */
void generar_arch(Twrkr vector[], int m, char *narchivo)
{
    FILE *fa;
    fa = fopen(narchivo, "w");

    printf("\n| No | STATUS  | No.TRabajador |  NOMBRE     |    APPAT     |   APMAT     |  SEXO  | Posicion |stado|edad |No.Telefono\n");
    for (int i = 0; i < m; i++)
    {
        if (vector[i].status == 1)
        {
            fprintf(fa, "%4d  %3d       %10d    %-10s   %-11s  %11s  %6s  %8s   %s  %d   %d\n",
                    i,
                    vector[i].status,
                    vector[i].enrollment,
                    vector[i].name,
                    vector[i].last_name_1,
                    vector[i].last_name_2,
                    vector[i].sex,
                    vector[i].job_pstion,
                    vector[i].state,
                    vector[i].age,
                    vector[i].cell_phone);
        }
    }
    printf("\n");
    fclose(fa);
}
/****************************************************** */
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
/****************************************************** */
int leer_archbin(Twrkr vector[], int m)
{
    int i = 0;
    FILE *fa = fopen("datos.dat", "rb");
    if (fa == NULL)
    {
        return 0; // no abrio el archivo
    }
    printf("|STATUS| No.trabajador| NOMBRE  |  APPAT       | GENERO |        edad | no.telefono| stado | posocion de trabajo\n");
    while (i < m && fread(&vector[i], sizeof(Twrkr), 1, fa) == 1)
    {
        printf(" %3d  %13d  %-10d  %-12s  %-12s  %c  %d  %d  %s  %s \n",
               i,
               vector[i].status,
               vector[i].enrollment,
               vector[i].name,
               vector[i].last_name_1,
               vector[i].last_name_2,
               vector[i].sex,
               vector[i].age,
               vector[i].cell_phone,
               vector[i].state,
               vector[i].job_pstion);
        i++;
    }

    fclose(fa);
    return i;
}
/****************************************************** */
int busqueda_secuencial_3(Twrkr vector[], int m) // uso esta para buscar en la modificacion de datos
{
    int num, pos;
    pos = busqueda_sec(vector, m, num);

    if (pos != -1)
    {
        printf("El trabajador existe\n");
    }
    else
    {
        printf("El trabajador no existe\n");
    }

    return pos;
}
/****************************************************** */
int cargar_archbin(Twrkr vector[], int m)
{
    int i = m;
    FILE *fa = fopen("datos.dat", "rb"); // abre el archivo
    if (fa == NULL)
    {
        return m;
    }

    while (i < inicializar() && fread(&vector[i], sizeof(Twrkr), 1, fa) == 1) // lee todo el archivo mientras que i menor a el tmaño osea inicializar
    {
        i++;
    }

    fclose(fa);
    return i;
}
/****************************************************** */
int inicializar()
{
    FILE *fa = fopen("datos.dat", "rb");
    int t_reg = 0;
    if (fa)
    {
        fseek(fa, 0, SEEK_END);
        int tam = ftell(fa);
        int total = tam / sizeof(Twrkr); // se sca el total
        if (total < 4)
        {
            t_reg = 4;
        }
        else
        {
            t_reg = (int)(total * 1.25);
        }
        fclose(fa);
    }
    else
    {
        t_reg = 4;
    }
    return t_reg;
}

//****************************************************
void claves(Usu registro, int m)
{
    FILE *fa = fopen("claves.dll", "ab");

    if (fa == NULL)
    {
        return; // no abrio
    }
    fwrite(&registro, sizeof(Usu), 1, fa);
    fclose(fa);
}

Usu agregar_usuario(Usu vector[], int m)
{
    Usu registros;
    int repetido;
    FILE *fa = fopen("claves.dll", "rb");
    Usu temp;

    do
    {
        repetido = 0;
        printf("Nombre de usuario: ");
        my_gets(registros.nomb, 30);
        if (fa != NULL)
        {
            while (fread(&temp, sizeof(Usu), 1, fa) == 1)
            {
                if ((strcmp(temp.nomb, registros.nomb) == 0) && (temp.statu == 1))
                {
                    printf("El nombre ya esta en uso. Intenta con otro.\n");
                    repetido = 1;
                    break;
                }
            }
            fclose(fa);
        }

    } while (repetido);
    leer_contrasena(registros.contra, 12);
    registros.nivel = validar(1, 3, "Nivel (1-3): ");
    registros.statu = 1;

    return registros;
}


void leer_contrasena(char contra[], int m)
{
    int i = 0;
    char caracter;
    printf("Ingresa la clave: ");
    while (1)
    {
        caracter = getch(); // lee sin mostrar
        if (caracter == 13)
        { // Enter
            break;
        }
        else if (caracter == 8)
        { // Backspace
            if (i > 0)
            {
                i--;
                printf("\b \b"); // borra el ultimo asterisco
            }
        }
        else if (i < m - 1)
        {
            contra[i++] = caracter;
            printf("*");
        }
    }

    contra[i] = '\0'; // Fin de cadena
    printf("\n");
}

int leer_archbin2(Usu vector[], int m)
{
    int i = 0;
    Usu temp;
    FILE *fa = fopen("claves.dll", "rb");
    if (fa == NULL)
    {
        return 0; // no abrio el archivo
    }
    printf("|NO| STATUS | NIVEL | Nombre|clave\n");
    while (fread(&temp, sizeof(Usu), 1, fa) == 1)
    {
        printf(" %d   %d          %d      %s   %s\n",
               i,
               temp.statu,
               temp.nivel,
               temp.nomb,
               temp.contra);
        i++;
    }
    fclose(fa);
    return i;
}

void iniciar_sesion()
{
    char nombre[30], clave[12];
    int intentos = 0;
    FILE *fa = fopen("claves.dll", "r+b"); // lectura y escritura binaria
    Usu temp;
    int encontrado;
    long pos;

    while (intentos < 3)
    {
        encontrado = 0;

        printf("Usuario: ");
        my_gets(nombre, 30);

        printf("Clave: ");
        leer_contrasena(clave, 12);

        if (fa == NULL)
        {
            printf("Error al abrir el archivo de usuarios.\n");
            exit(1);
        }

        while (fread(&temp, sizeof(Usu), 1, fa) == 1)
        {
            if (strcmp(temp.nomb, nombre) == 0)
            {
                encontrado = 1;
                if (temp.statu == 2)
                {
                    printf("Usuario bloqueado, contacte al administrador.\n");
                    fclose(fa);
                    exit(0);
                }
                else if (strcmp(temp.contra, clave) == 0)
                {
                    printf("Bienvenido, %s.\n", temp.nomb);
                    nivel_usu = temp.nivel;
                    fclose(fa);
                    return; // acceso correcto
                }
                else
                {
                    // Contraseña incorrecta
                    intentos++;
                    if (intentos >= 3)
                    {
                        // Bloquear usuario
                        pos = ftell(fa) - sizeof(Usu);     // posicion actual
                        fseek(fa, pos, SEEK_SET);          // mueve el cursor
                        temp.statu = 2;                    // bloqueado
                        fwrite(&temp, sizeof(Usu), 1, fa); // escribe de nuevo pero con estatu en 2
                        fclose(fa);

                        printf("Demasiados intentos, Usuario bloqueado.\n");
                        exit(0); // cierra todo
                    }
                    else
                    {
                        printf("Clave incorrecta\n");
                    }
                    break;
                }
            }
        }
        fclose(fa);
        if (!encontrado)
        {
            printf("Usuario no encontrado.\n");
            intentos++;
            if (intentos >= 3)
            {
                printf("Demasiados intentos.\n");
                exit(0); // cerramos todo
            }
        }
    }
}

// void eliminar_usuario();

// void modificar_nivel();

// void desbloquear_usuario();
//modificar para que lo busque con el nombre
void elimina_usu(Usu vector[], int m)
{
    int matri;
    matri = validar(300000, 399999, "Que trabajador vas a borrar?\n");
    int posi = busqueda_secuencial_3(vector, m);
    int res;
    if (posi != -1)
    {
        printf("DATOS DEL Usuario\n");
        printf("Nombre de usuario: %d\n", vector[posi].nomb);
        printf("Trabajador: %s %s %s\n", vector[posi].name, vector[posi].last_name_1, vector[posi].last_name_2);
        printf("No. de telefono: %d\n", vector[posi].cell_phone);

        res = validar(1, 2, "Seguro quieres eliminarlo?  1 para si 2 para no\n");
        if (res == 1)
        {
            for (int i = 0; i < m; i++)
            {
                if (vector[i].status == 1 && vector[i].enrollment == matri)
                {
                    vector[i].status = 0;
                    printf("El trabajador %d se elimino\n", matri);
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
        printf("El trabajador no existe.\n");
    }
}

void modi_nivel()
{




    
}
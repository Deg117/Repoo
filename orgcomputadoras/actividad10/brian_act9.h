#include "curp3.h"

typedef long Tkey;
typedef struct _nacimiento
{
    int dia;
    int mes;
    int anio;

} f_naci;

typedef struct _talum
{
    Tkey llave;
    int status; // 1 activo 0 inactivo
    int matri;
    char nombre[50];
    char apperno[30];
    char apmaterno[30];
    char curp[19];
    f_naci fecha_n;
    int edad;
    char lug_naci[3];
    int sexo; // 1 para H 2 para mujer
} Ts_alum;

// nueva libreria para esta actividad ya que la otra estab demaciado desordenada
// y con funciones no necesarias en esta actividad
f_naci fecha1();
void lug_naci(Ts_alum *reg);
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
int busqueda_secuencial_2(Ts_alum vector[], int m);
dt_curp nueva_curp(Ts_alum reg, dt_curp *reg2);
int ordenado = 0;

void opciones()
{
    Ts_alum reg;
    Ts_alum vector;
    Ts_alum vector_reg[3500];
    int op, opc;
    int j = 0;
    int band = 0;
    int llena = 0; // la uso para llevar orden en ordenamiento
    do
    {
        printf("1-Agregar\n");
        printf("2-Eliminar registro\n");
        printf("3-Buscar\n");
        printf("4-Ordenar\n");
        printf("5-Imprimir\n");
        printf("6-Modificar\n");
        printf("0.-Salir\n");
        op = validar(0, 6, "Dame una opcion\n");
        system("CLS");
        switch (op)
        {
        case 1:
            int opci;
            do
            {

                printf("1-Agregar manual (1)\n");
                printf("2-Agregar automatico (100)\n");
                printf("0-Regresar\n");
                opci = validar(0, 2, "Dame una opcion\n");
                system("CLS");
                switch (opci)
                {
                case 2:
                    for (int i = 0; i < 100; i++)
                    {
                        reg = agregar_aleato(vector_reg);
                        vector_reg[j++] = reg;
                    }
                    printf("Todo bien\n"); // para que sepa que se agregaron bien
                    band = 1;
                    llena = 1;
                    ordenado = 0;
                    break;
                case 1:
                    reg = agregar_manu(vector_reg);
                    vector_reg[j++] = reg;
                    system("CLS");
                    band = 1;
                    llena = 1;
                    ordenado = 0;
                }
            } while (opci != 0);
            break;

        case 2:
            if (band)
            {
                do
                {
                    elimina_reg(vector_reg, j);
                    opc = validar(0, 1, "Quieres continuar borrando? \n(1 para si, 0 para no)\n");
                    system("CLS");
                } while (opc != 0);
            }
            else
            {
                printf("Agrega alumnos primero si no que eliminas?\n"); // recordatorio de que esta vacio
            }
            break;
        case 3:
            if (llena == 0)
            {
                printf("Agrega algo si no que buscas...\n"); // otro mensajito
            }
            else
            {
                if (ordenado == 0)
                {
                    printf("Busqueda secuencial\n:");
                }
                else
                {
                    printf("Busqueda Binaria\n:");
                    busqueda_bin(vector_reg, j);
                }
            }
            break;
        case 4:
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
        case 5:
            if (band)
            {
                imp_vect_reg(vector_reg, j);
            }
            else
            {
                printf("Agrega alumnos primero si no que te muestro...\n");
            }
            break;
        case 6:
            dt_curp n_curp;
            if (band)
            {
                int posi = busqueda_secuencial_2(vector_reg, j);
                if (posi != -1) 
                {
                    printf(" DATOS DEL ALUMNO \n");
                    printf("Matricula: %d\n", vector_reg[posi].matri);
                    printf("Nombre: %s\n", vector_reg[posi].nombre);
                    printf("Apellido paterno: %s\n", vector_reg[posi].apperno);
                    printf("Apellido materno: %s\n", vector_reg[posi].apmaterno);
                    printf("Edad: %d\n", vector_reg[posi].edad);
                    printf("Fecha de nacimiento: %02d/%02d/%04d\n",
                           vector_reg[posi].fecha_n.dia,
                           vector_reg[posi].fecha_n.mes,
                           vector_reg[posi].fecha_n.anio);
                    printf("Lugar de nacimiento: %s\n", vector_reg[posi].lug_naci);
                    printf("CURP: %s\n", vector_reg[posi].curp);
                    do
                    {
                        printf("1-Nombre\n");
                        printf("2-Apellido paterno\n");
                        printf("3-Apellido materno\n");
                        printf("4-Edad\n");
                        printf("5-Fecha de nacimiento\n");
                        printf("6-Lugar de nacimiento\n");
                        printf("7-Ya nada\n");
                        opc = validar(1, 7, "Que quieres modificar?\n");
                        system("CLS");

                        switch (opc)
                        {
                        case 1:
                            printf("Nuevo nombre:\n");
                            my_gets2(vector_reg[posi].nombre, 30);
                            mayus(vector_reg[posi].nombre);
                            break;
                        case 2:
                            printf("Nuevo apellido paterno:\n");
                            my_gets2(vector_reg[posi].apperno, 30);
                            mayus(vector_reg[posi].apperno);
                            break;
                        case 3:
                            printf("Nuevo apellido materno:\n");
                            my_gets2(vector_reg[posi].apmaterno, 30);
                            mayus(vector_reg[posi].apmaterno);
                            break;
                        case 4:
                            vector_reg[posi].edad = validar(1, 90, "Nueva edad:");
                            break;
                        case 6:

                            n_curp = lug_nacimiento(n_curp);
                            copiar(vector_reg[posi].lug_naci, n_curp.lug_nacimiento);
                            break;

                        case 5:
                            vector_reg[posi].fecha_n = fecha1();
                            break;
                        case 7:
                            printf("Terminaste de modificar.\n");
                            break;
                        }

                    } while (opc != 7);
                    dt_curp n_curp = nueva_curp(vector_reg[posi], &n_curp);
                    generar_curp(&n_curp);
                    copiar(vector_reg[posi].curp, n_curp.curp);
                }
            }
            else
            {
                printf("Agrega alumnos primero, si no que te modifico rey?\n");
            }
            break;
        case 0:
            printf("saliendo\n");
            break;
        }
    } while (op != 0);
}

dt_curp nueva_curp(Ts_alum reg, dt_curp *reg2)// qui copio todos los datos para la curp
{
    dt_curp alumno;
    copiar((*reg2).nombre, reg.nombre);
    copiar((*reg2).paterno, reg.apperno);
    copiar((*reg2).materno, reg.apmaterno);
    (*reg2).anio = reg.fecha_n.anio;
    (*reg2).mes = reg.fecha_n.mes;
    (*reg2).dia = reg.fecha_n.dia;
    (*reg2).sex = reg.sexo;
    copiar((*reg2).lug_nacimiento, reg.lug_naci);
    penultimo(&(*reg2));
    ultimo(&(*reg2));
    return alumno;
}

Ts_alum agregar_aleato(Ts_alum vector[]) // reiniciar el ciclo cada que se llame
{
    Ts_alum reg;
    int j = 0;

    if (j >= 2500) // Verificar que no exceda el tamaño del vector
    {
        printf("Vector lleno\n");
    }
    char nomh[30][10] = {"CHABELO", "BRIAN", "WILLIAM", "KEVIN", "ANGEL",
                         "ISIDRO", "JORGE", "JOSE", "MARIO", "ERICK",
                         "ALAN", "CARLOS", "DIEGO", "EDGAR", "FELIX",
                         "GUSTAVO", "HUGO", "IVAN", "JAVIER", "LUIS",
                         "MANUEL", "NESTOR", "OSCAR", "PABLO", "QUINTIN",
                         "RAUL", "SAMUEL", "TONY", "ULISES", "VICTOR"};
    char nomm[30][15] = {"SOFIA", "ALMA", "VICTORIA", "KARLA", "IVANA",
                         "NELLY", "KIYUMI", "TANYA", "DAYANA", "CLAUDIA",
                         "MARIA", "FERNANDA", "PAOLA", "JULIETA", "PAMELA",
                         "MIRIAM", "VALERIA", "ALEJANDRA", "GABRIELA", "LILIANA",
                         "SANDRA", "ARACELY", "YAZMIN", "MONICA", "PATRICIA",
                         "LOURDES", "JACQUELINE", "ROSARIO", "VERONICA", "GUADALUPE"};
    char ape[30][15] = {"GASTELUM", "GOZA", "BAEZ", "MARCELA", "OBRADOR",
                        "ZAZUETA", "CARRERA", "FELIX", "SHEINBAUM", "NEVAREZ",
                        "LOPEZ", "HERNANDEZ", "GOMEZ", "RAMIREZ", "TORRES",
                        "CRUZ", "SANDOVAL", "SOTO", "REYES", "MENDOZA",
                        "NAVARRO", "RODRIGUEZ", "AGUILAR", "CASTILLO", "VARGAS",
                        "CORTES", "SALAZAR", "IBARRA", "LUNA", "PEREZ"};
    int sex[2] = {1, 2};
    reg.status = 1;
    reg.matri = (rand() % 99999) + 300000;
    while (no_repetidos(vector, 2500, reg.matri))
    {
        reg.matri = (rand() % 99999) + 300000;
    }
    copiar(reg.apperno, ape[rand() % 30]);
    copiar(reg.apmaterno, ape[rand() % 30]);

    if ((rand() % 2) == 0)
    {
        copiar(reg.nombre, nomh[rand() % 30]);
        reg.sexo = 'H'; // Hombre
    }
    else
    {
        copiar(reg.nombre, nomm[rand() % 30]);
        reg.sexo = 'M'; // Mujer
    }
    reg.edad = (rand() % 82) + 18;
    reg.fecha_n.anio = (rand() % (2006 - 1900 + 1)) + 1900;
    reg.fecha_n.mes = (rand() % 12) + 1;
    reg.fecha_n.dia = (rand() % 28) + 1;
    copiar(reg.lug_naci, estados[rand() % 33]);
    dt_curp n_curp = nueva_curp(reg, &n_curp);
    generar_curp(&n_curp);
    copiar(reg.curp, n_curp.curp);
    (j)++;

    return reg;
}

Ts_alum agregar_manu(Ts_alum vector[])
{
    Ts_alum reg;
    reg.status = 1;
    int i;
    reg.matri = validar(300000, 399999, "Matricula\n");
    system("CLS");
    while (no_repetidos(vector, 2500, reg.matri))
    {
        printf("Dame una matricula que no exista por favor\n:");
        reg.matri = validar(300000, 399999, "Matricula\n");
    }

    printf("Nombre\n");
    my_gets2(reg.nombre, 50);
    mayus(reg.nombre);
    system("CLS");
    while (!solo_letras(reg.nombre))
    {
        printf("Solo se permiten letras \n.Dame un nombre valido\n");
        my_gets2(reg.nombre, 50);
        mayus(reg.nombre);
        system("CLS");
    }
    printf("Apellido paterno\n");
    my_gets2(reg.apperno, 30);
    mayus(reg.apperno);
    system("CLS");

    while (!solo_letras(reg.apperno))
    {
        printf("Solo se permiten letras \n Dame un apellido valido\n");
        my_gets2(reg.apperno, 30);
        mayus(reg.apperno);
        system("CLS");
    }
    printf("Apellido materno\n");
    my_gets2(reg.apmaterno, 30);
    mayus(reg.apmaterno);
    system("CLS");
    while (!solo_letras(reg.apmaterno))
    {
        printf("Solo se permiten letras \nDame un apellido valido\n");
        my_gets2(reg.apmaterno, 30);
        mayus(reg.apmaterno);
        system("CLS");
    }
    printf("Sexo\n");
    reg.sexo = validar(1, 2, "Dame 1 para Hombre o 2 para Mujer\n");
    if (reg.sexo == 1)
    {
        reg.sexo = 'H';
    }
    else
    {
        reg.sexo = 'M';
    }
    system("CLS");
    reg.edad = validar(10, 90, "Dame te edad\n");
    reg.fecha_n = fecha1();
    system("CLS");
    lug_naci(&reg);
    dt_curp n_curp = nueva_curp(reg, &n_curp);
    generar_curp(&n_curp);
    copiar(reg.curp, n_curp.curp);
    return reg;
}

void imp_vect_reg(Ts_alum vector[], int m) // acomodar impresion
{
    char sex[30];
    printf("\n  No|   STATUS|  MATRICULA|   NOMBRE      |   APPAT     |   APMAT     |    EDAD|   SEXO  | FECHA N.     |Estado    |  CURP\n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < m; i++)
    {
        if (vector[i].status == 1)
        {
            if (vector[i].sexo == 'H')
            {
                copiar(sex, "M");
            }
            else
            {
                copiar(sex, "F");
            }
            printf("%4d|   %3d   |   %8d|   %-12s|   %-10s|   %-10s|   %5d|   %6s|  %d/%d/%d    |  %2s     |  %s\n",
                   i, vector[i].status, vector[i].matri, vector[i].nombre,
                   vector[i].apperno, vector[i].apmaterno, vector[i].edad, sex,
                   vector[i].fecha_n.dia, vector[i].fecha_n.mes, vector[i].fecha_n.anio, vector[i].lug_naci, vector[i].curp);
        }
    }
    printf("\n");
    system("pause");
    system("CLS");
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

f_naci fecha1()
{
    f_naci reg;
    int bisi;
    reg.anio = validar(1900, 2025, "Nacimiento\n");
    reg.mes = validar(1, 12, "Mes de Nacimiento\n");
    switch (reg.mes)
    {
    case 1:
        reg.dia = validar(1, 31, "Dia de nacimiento\n");
        break;
    case 2:
        bisi = reg.anio % 4; // por si naciste el 29 de febrero si no pss el 28 tal vez
        if (bisi == 0)
        {
            reg.dia = validar(1, 29, "Dia de nacimiento");
        }
        else
        {
            reg.dia = validar(1, 28, "Dia de nacimiento");
        }
        break;
    case 3:
        reg.dia = validar(1, 31, "Dia de nacimiento\n");
        break;
    case 4:
        reg.dia = validar(1, 30, "Dia de nacimiento\n");
        break;
    case 5:
        reg.dia = validar(1, 31, "Dia de nacimiento\n");
        break;
    case 6:
        reg.dia = validar(1, 30, "Dia de nacimiento\n");
        break;
    case 7:
        reg.dia = validar(1, 31, "Dia de nacimiento\n");
        break;
    case 8:
        reg.dia = validar(1, 31, "Dia de nacimiento\n");
        break;
    case 9:
        reg.dia = validar(1, 30, "Dia de nacimiento\n");
        break;
    case 10:
        reg.dia = validar(1, 31, "Dia de nacimiento\n");
        break;
    case 11:
        reg.dia = validar(1, 30, "Dia de nacimiento\n");
        break;
    case 12:
        reg.dia = validar(1, 31, "Dia de nacimiento\n");
        break;
    }
    return reg;
}

void lug_naci(Ts_alum *reg)
{
    int lugar;
    int num = 1;
    printf("Selecciona tu lugar de nacimiento\n");
    for (int i = 0; i < 33; i++)
    {
        printf("%d-%s\n", num, estado[i]);
        num++;
    }
    lugar = validar(1, 33, "Lugar de nacimiento\n");
    copiar(reg->lug_naci, estados[lugar-1]);
}

int busqueda_secuencial_2(Ts_alum vector[], int m)//uso esta para buscar en la modificacion de datos
{
    int num, pos;
    num = validar(300000, 399999, "Quieres modificar, Deme la matricula\n");
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
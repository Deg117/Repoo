#include "brian.h"

typedef struct dt_curp
{
    char nombre[50];
    char paterno[50];
    char materno[50];
    char lug_nacimiento[3];
    char sex;
    int anio;
    int mes;
    int dia;
    char penultimo;
    int ultimo;
} dt_curp;

const char *estado[] = {
    "Aguascalientes", "Baja California", "Baja California Sur", "Campeche", "Coahuila", "Colima", "Chiapas", "Chihuahua", "Distrito Federal",
    "Durango", "Guanajuato", "Guerrero", "Hidalgo", "Jalisco", "Mexico", "Michoacan", "Morelos", "Nayarit", "Nuevo Leon", "Oaxaca", "Puebla", "Queretaro", "Quintana Roo",
    "San Luis Potosi", "Sinaloa", "Sonora", "Tabasco", "Tamaulipas", "Tlaxcala", "Veracruz", "Yucatan", "Zacatecas", "Extranjero"};

const char *estados[] = {"AS", "BC", "BS", "CC", "CL", "CM", "CS", "CH", "DF", "DG",
                         "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC",
                         "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ",
                         "YN", "ZS", "NE"};

const char *pal_prohibi[] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CACO", "COGE", "COGI", "COJA",
                             "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA",
                             "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO",
                             "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO",
                             "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO",
                             "QULO", "RATA", "ROBA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA",
                             "VUEI", "VUEY", "WUEI", "WUEY"};
#define prohibi 69
const char *basura[19] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "Y", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON"};

void datos(dt_curp reg);
int comparar(const char texto[], const char texto2[]);
void copiar(char *destino, const char *origen);
int pal_valida(char curp[]);
dt_curp nombre();
void principal();
void mayus(char texto[]);
int solo_letras(char texto[]);
char *my_gets2(char *cadena, int tamano);
dt_curp fecha();
void generar_curp(dt_curp reg);
dt_curp sex();
dt_curp lug_nacimiento(dt_curp reg);
dt_curp ultimo(dt_curp reg);
char conso_paterno(dt_curp reg);
char conso_materno(dt_curp reg);
char conso_nombre(dt_curp reg);
dt_curp penultimo(dt_curp reg);
int longitud_cadena(const char *cadena);
int div_apellido(char *reg, char div_ape[][50], char espacio);
void quitar_basura(char apellido[][50], int fila, int *fila_maxi);

void principal() // lamamos tods los datos
{
    srand(time(NULL));
    dt_curp reg;
    int i;
    reg = nombre();
    system("CLS");
    reg = fecha();
    system("CLS");
    reg = sex();
    system("CLS");
    reg = lug_nacimiento(reg);
    system("CLS");
    reg = penultimo(reg);
    system("CLS");
    reg = ultimo(reg);
    system("CLS");
    generar_curp(reg);
    datos(reg);
    system("pause");
}

void datos(dt_curp reg) // mostramos los datos como nombre genero etc..
{
    char sex[30];
    printf("Nombre Completo\n");
    printf("%2s %2s %2s\n", reg.nombre, reg.paterno, reg.materno);
    printf("Fecha de nacimiento\n");
    printf("%d/%d/%d\n", reg.dia, reg.mes, reg.anio);
    printf("Lugar de nacimiento\n");
    for (int i = 0; i < 33; i++)
    {
        if (!comparar(reg.lug_nacimiento, estados[i])) // lit compara reg con estados de i los cuales son abrebiados
        {

            printf("%s\n", estado[i]); // devuelve el estado no abrebiado de SL a sinaloa
            break;
        }
    }
    printf("Genero\n");
    if (reg.sex == 72) // 72 en ascii es H
    {
        copiar(sex, "Hombre");
    }
    else
    {
        copiar(sex, "Mujer");
    }
    printf("%s\n", sex);
}

void generar_curp(dt_curp reg)
{

    int i = 1, j = 1;
    char curp[19] = {0};
    char div_ape_mater[20][50];
    char div_ape[20][50] = {'\0'};

    int m_filas = div_apellido(reg.paterno, div_ape, ' ');
    quitar_basura(div_ape, 20, &m_filas); // adios palabras que no sirven antres del apellido del de la etc..
    int indi_p = 0;
    int indi_m = 0;
    curp[0] = div_ape[indi_p][0];
    curp[1] = div_ape[indi_p][1];
    while (div_ape[indi_p][i] != '\0') // dividimos el apellido en busca de bocales
    {
        if (div_ape[indi_p][i] == 'A' || div_ape[indi_p][i] == 'E' || div_ape[indi_p][i] == 'I' || div_ape[indi_p][i] == 'O' || div_ape[indi_p][i] == 'U')
        {
            curp[1] = div_ape[indi_p][i]; // encontre la bocal ahora va pa tras
            break;
        }
        i++;
    }

    int filas = div_apellido(reg.materno, div_ape_mater, ' ');
    quitar_basura(div_ape_mater, 20, &filas);
    curp[2] = div_ape_mater[indi_m][0];

    // curp[2] = reg.materno[0];//en su momento se uso
    curp[3] = reg.nombre[0];
    curp[4] = (reg.anio % 100) / 10 + '0'; // +0 para convertirlo en caracter al igual las siguientes
    curp[5] = (reg.anio % 10) + '0';
    curp[6] = (reg.mes / 10) + '0';
    curp[7] = (reg.mes % 10) + '0';
    curp[8] = (reg.dia / 10) + '0';
    curp[9] = (reg.dia % 10) + '0';
    curp[10] = reg.sex;
    curp[11] = reg.lug_nacimiento[0];
    curp[12] = reg.lug_nacimiento[1];
    curp[13] = conso_paterno(reg);
    curp[14] = conso_materno(reg); // se busca la consonante en la funcion
    curp[15] = conso_nombre(reg);
    curp[16] = reg.penultimo;
    curp[17] = reg.ultimo;
    curp[18] = '\0';
    if (pal_valida(curp)) // revisamos palabras inconvenientes pq no te quieres llevar eso en tu curp
    {
        curp[1] = 'X'; // x por si tenia una palabra de esas
    }

    printf("CURP %s\n", curp);
}

dt_curp nombre()
{
    dt_curp reg; // pa mandar pa atras los datos de aqui
    printf("Nombre(s):\n");
    my_gets2(reg.nombre, 50); // la funcion tuneada de my gets
    mayus(reg.nombre);
    while (!solo_letras(reg.nombre)) // revisamos las letras que nos den
    {
        printf("Solo se permiten letras \n.Dame un nombre valido\n");
        my_gets2(reg.nombre, 50);
        mayus(reg.nombre);
    }
    printf("Apellido Paterno:\n");
    my_gets2(reg.paterno, 50);
    mayus(reg.paterno);
    while (!solo_letras(reg.paterno))
    {
        printf("Solo se permiten letras \n.Dame un apellido valido\n");
        my_gets2(reg.paterno, 50);
        mayus(reg.paterno);
    }
    printf("Apellido Materno:\n");
    my_gets2(reg.materno, 50);
    mayus(reg.materno);
    while (!solo_letras(reg.materno))
    {
        printf("Solo se permiten letras \n.Dame un apellido valido\n");
        my_gets2(reg.materno, 50);
        mayus(reg.materno);
    }
    return reg;
}

int div_apellido(char *reg, char div_ape[][50], char espacio) // divide el apellido por si nos dan tipo de la cruz
{

    int fil = 0, colum = 0;
    for (int i = 0; i < longitud_cadena(reg); i++)
    {
        if (reg[i] == espacio)
        {
            div_ape[fil][colum] = '\0';
            fil++;
            colum = 0;
        }
        else
        {
            div_ape[fil][colum] = reg[i];
            colum++;
        }
    }
    div_ape[fil][colum] = '\0';

    return fil + 1;
}

void quitar_basura(char apellido[][50], int fila, int *fila_maxi) // chao basurita de la el del etc..
{
    for (int i = 0; i < fila; i++) // recorre la fila
    {
        for (int j = 0; j < 19; j++) // recorre columna
        {
            if (comparar(apellido[i], basura[j]) == 0) // lit compara si el apellido aun tiene o no basura
            {
                apellido[i][0] = '\0';
                for (int k = i; k < fila - 1; k++)
                {
                    copiar(apellido[k], apellido[k + 1]); // recorre el apellido por que ya elimino la basura
                }
                apellido[fila - 1][0] = '\0'; // tambien recorre filas que no se usaran mas
                (*fila_maxi)--;
                fila--;
                i--;
                break;
            }
        }
    }
}

int pal_valida(char curp[])
{
    int band = 0;
    for (int i = 0; i < prohibi; i++)
    {
        int igual = 1;              // las palabras son iguales solo para comenzar
        for (int j = 0; j < 4; j++) // Comparamos 4 caracteres
        {
            if (curp[j] != pal_prohibi[i][j]) // no son iguales
            {
                igual = 0; // igual sera 0
                break;
            }
        }

        if (igual) // Si son iguales la bandera sera 1
        {
            band = 1;
            return 1; // Es una palabra malita
        }
    }

    if (band == 1)
    {
        curp[1] = 'X'; // Cambia la segunda letra
    }

    return 0; // No es malita
}

int longitud_cadena(const char *cadena) // el reemplazo de strlen o algo asi era
{
    int longi = 0;
    while (cadena[longi] != '\0')
    {
        longi++;
    }

    return longi;
}

dt_curp lug_nacimiento(dt_curp reg)
{
    int lugar;
    int num = 1;
    printf("Selecciona tu lugar de nacimiento\n");
    for (int i = 0; i < 33; i++)
    {
        printf("%d-%s\n", num, estado[i]);
        num++;
    }
    /*
    printf("1-Aguas calientes\n");
    printf("2-Baja california\n");
    printf("3-Baja california sur\n");
    printf("4-Campeche\n");
    printf("5-Coahuila\n");
    printf("6-Colima\n");
    printf("7-Chiapas\n");
    printf("8-Chihuahua\n");
    printf("9-Distrito Federal\n");
    printf("10-Durango\n");
    printf("11-Guanajuato\n");
    printf("12-Guerrero\n");
    printf("13-Hidalgo\n");
    printf("14-Jalisco\n");
    printf("15-Mexico\n");
    printf("16-Michoacan\n");
    printf("17-Morelos\n");
    printf("18-Nayarit\n");
    printf("19-Nuevo Leon\n");
    printf("20-Oaxaca\n");
    printf("21-Puebla\n");
    printf("22-Queretaro\n");
    printf("23-Quintana Roo\n");
    printf("24-San luis potosi\n");
    printf("25-Sinaloa\n");
    printf("26-Sonora\n");
    printf("27-Tabasco\n");
    printf("28-Tamaulipas\n");
    printf("29-Tlaxcala\n");
    printf("30-Veracruz\n");
    printf("31-YUcatan\n");
    printf("32-Zacatecas\n");
    printf("33-Extranjero\n");*/
    lugar = validar(1, 33, "Lugar de nacimiento\n");
    switch (lugar)
    {
    case 1:
        copiar(reg.lug_nacimiento, estados[0]); // funcion strcpy pero sin string lit es copiar, lugar de destino y el origen del dato
        break;
    case 2:
        copiar(reg.lug_nacimiento, estados[1]); // de aqui para alla tambien 1-33
        break;
    case 3:
        copiar(reg.lug_nacimiento, estados[2]);
        break;
    case 4:
        copiar(reg.lug_nacimiento, estados[3]);
        break;
    case 5:
        copiar(reg.lug_nacimiento, estados[4]);
        break;
    case 6:
        copiar(reg.lug_nacimiento, estados[5]);
        break;
    case 7:
        copiar(reg.lug_nacimiento, estados[6]);
        break;
    case 8:
        copiar(reg.lug_nacimiento, estados[7]);
        break;
    case 9:
        copiar(reg.lug_nacimiento, estados[8]);
        break;
    case 10:
        copiar(reg.lug_nacimiento, estados[9]);
        break;
    case 11:
        copiar(reg.lug_nacimiento, estados[10]);
        break;
    case 12:
        copiar(reg.lug_nacimiento, estados[11]);
        break;
    case 13:
        copiar(reg.lug_nacimiento, estados[12]);
        break;
    case 14:
        copiar(reg.lug_nacimiento, estados[13]);
        break;
    case 15:
        copiar(reg.lug_nacimiento, estados[14]);
        break;
    case 16:
        copiar(reg.lug_nacimiento, estados[15]);
        break;
    case 17:
        copiar(reg.lug_nacimiento, estados[16]);
        break;
    case 18:
        copiar(reg.lug_nacimiento, estados[17]);
        break;
    case 19:
        copiar(reg.lug_nacimiento, estados[18]);
        break;
    case 20:
        copiar(reg.lug_nacimiento, estados[19]);
        break;
    case 21:
        copiar(reg.lug_nacimiento, estados[20]);
        break;
    case 22:
        copiar(reg.lug_nacimiento, estados[21]);
        break;
    case 23:
        copiar(reg.lug_nacimiento, estados[22]);
        break;
    case 24:
        copiar(reg.lug_nacimiento, estados[23]);
        break;
    case 25:
        copiar(reg.lug_nacimiento, estados[24]);
        break;
    case 26:
        copiar(reg.lug_nacimiento, estados[25]);
        break;
    case 27:
        copiar(reg.lug_nacimiento, estados[26]);
        break;
    case 28:
        copiar(reg.lug_nacimiento, estados[27]);
        break;
    case 29:
        copiar(reg.lug_nacimiento, estados[28]);
        break;
    case 30:
        copiar(reg.lug_nacimiento, estados[29]);
        break;
    case 31:
        copiar(reg.lug_nacimiento, estados[30]);
        break;
    case 32:
        copiar(reg.lug_nacimiento, estados[31]);
        break;
    case 33:
        copiar(reg.lug_nacimiento, estados[32]);
        break;
    }
    return reg;
}

dt_curp fecha()
{
    dt_curp reg;
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
dt_curp sex()
{
    dt_curp reg;
    reg.sex = validar(1, 2, "Sexo\n1- Hombre, 2- Mujer\n"); // solo para dos generos

    switch (reg.sex)
    {
    case 1:
        reg.sex = 'H';
        break;

    case 2:
        reg.sex = 'M';
        break;
    }
    return reg;
}

char *my_gets2(char *cadena, int tamano) // se agrega que no inicie en 0 y tampoco en espacio
{
    int longitud = 0;
    do
    {
        fflush(stdin);
        fgets(cadena, tamano, stdin);
        longitud = longitud_cadena(cadena); // estrenando longitud_cadena

        if (longitud > 0 && cadena[longitud - 1] == '\n') // revisa la cadena
        {
            cadena[longitud - 1] = '\0';
            longitud--;
        }
        if (longitud == 0)
        {
            printf("No puedes dejar vacio...\n"); // mensajito amables
        }
        else if (cadena[0] == ' ')
        {
            printf("No puedes comenzar con espacio...\n");
        }

    } while (longitud == 0 || cadena[0] == ' ');

    return cadena;
}

void mayus(char texto[])
{
    int i;
    for (i = 0; texto[i] != '\0'; i++)
    {
        if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            texto[i] -= 32;
        }
        if (texto[i] == -15) // la ñ minuscula
        {
            texto[i] -= 32;
        }
    }
}

int solo_letras(char texto[])
{
    int i = 0;
    while (texto[i] != '\0')
    {
        if (!isalpha(texto[i]) && texto[i] != ' ' && texto[i] != -15 && texto[i] != -47) // la ñ mayuscula
        {
            return 0; // tiene numeros o algo que no son letras
        }
        i++;
    }
    return 1; // dato valido
}

char conso_paterno(dt_curp reg)
{
    char div_ape[20][50] = {'\0'}; // para el apellido

    int m_filas = div_apellido(reg.paterno, div_ape, ' ');
    quitar_basura(div_ape, 20, &m_filas);
    int indi_p = 0;
    int i = 1; // Empezamos en 1 para saltar la primer letra del apellido
    while (div_ape[indi_p][i] != '\0')
    {
        if (div_ape[indi_p][i] != 'A' && div_ape[indi_p][i] != 'E' && div_ape[indi_p][i] != 'I' && div_ape[indi_p][i] != 'O' && div_ape[indi_p][i] != 'U')
        {
            if (div_ape[indi_p][i] == -47) // con la ñ no se muestra mandamos x a curp
            {
                return 'X';
            }
            return div_ape[indi_p][i]; // manda la primer consonante que encuentre en el apellido
        }
        i++;
    }
    return 'X'; // Si no tiene conosonantes sera x
}

char conso_materno(dt_curp reg) // aca obtenemos las consonantes del apellido
{

    char div_ape_mater[20][50] = {'\0'};

    int m_filas = div_apellido(reg.materno, div_ape_mater, ' ');
    quitar_basura(div_ape_mater, 20, &m_filas);
    int indi_p = 0;
    int i = 1; // Empezamos en 1 para saltar la primer letra del apellido
    while (div_ape_mater[indi_p][i] != '\0')
    {
        if (div_ape_mater[indi_p][i] != 'A' && div_ape_mater[indi_p][i] != 'E' && div_ape_mater[indi_p][i] != 'I' && div_ape_mater[indi_p][i] != 'O' && div_ape_mater[indi_p][i] != 'U')
        {
            if (div_ape_mater[indi_p][i] == -47) // aca tambien mandamos x
            {
                return 'X';
            }
            return div_ape_mater[indi_p][i]; // manda la primer consonante que encuentre en el apellido
        }
        i++;
    }
    return 'X'; // Si no tiene conosonantes sera x
}
char conso_nombre(dt_curp reg)
{

    int i = 1; // Empezamos en 1 para saltar la primer letra del apellido
    while (reg.nombre[i] != '\0')
    {
        if (reg.nombre[i] != 'A' && reg.nombre[i] != 'E' && reg.nombre[i] != 'I' && reg.nombre[i] != 'O' && reg.nombre[i] != 'U')
        {

            if (reg.nombre[i] == -47) // x tambien
            {
                return 'X';
            }
            return reg.nombre[i]; // manda la primer consonante que encuentre en el apellido
        }
        i++;
    }
    return 'X'; // Si no tiene conosonantes sera x
}

dt_curp penultimo(dt_curp reg) // si eres del 2000 o mas A si eres menos del 2000 toca un 0
{

    if (reg.anio < 2000)
    {
        reg.penultimo = '0';
    }
    else
    {
        reg.penultimo = 'A';
    }
    return reg;
}

dt_curp ultimo(dt_curp reg)
{
    reg.ultimo = rand() % 10 + '0'; // aleatorio de 0 a 9 se le suma el '\0' para convertirlo a caracter y asi se pueda mostrar
    return reg;
}

void copiar(char *destino, const char *origen) // strcpy pirata
{
    int i = 0;
    while (origen[i] != '\0')
    {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0'; // Asegura que la cadena termine correctamente
}

int comparar(const char texto[], const char texto2[]) // strcmpy pirata
{
    int indi = 0;
    while (texto[indi] != '\0' && texto2[indi] != '\0') // los dos textos los compara si son diferentes entra al if
    {
        if (texto[indi] != texto2[indi]) // si se cumple
        {
            return texto[indi] - texto2[indi]; // manda la iferencia de caracteres
        }
        indi++;
    }

    // Si una cadena es mas larga que la otra
    return texto[indi] - texto2[indi];
}
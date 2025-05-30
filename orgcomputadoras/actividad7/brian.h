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
    //printf("Dame una palabra para darte la cantidad de caracteres:\n");
   // my_gets(texto, 50);
    while (texto[i] != '\0')
    {
        total++;
        i++;
    }
    //printf("La cantidad de caracteres es:\n");
    //printf("%d\n", total);

    return total;
}

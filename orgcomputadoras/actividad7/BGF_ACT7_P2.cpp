/*Brian De Jesus Gatelum Fierro
Matricula:373408
parte 2
14/03/2025-15/03/2025
BGF_ACT7_PE_.CPP
*/
#include "brian.h"
void principal(char texto[]);
void inverso(char texto[]);

int main()
{
    char texto[50] = {'\0'};
    principal(texto);
}


void inverso(char texto[])
{
    int i, tam;
    tam = caracteres(texto);
    for (i = tam; i >= 0; i--)
    {
        // texto[i]=texto[tam -1 -i];
        printf("%c", texto[i]);
    }
    // printf("La palabra invertida es:\n");
    //printf("%s",);
    //tam[i] = '\0';
}


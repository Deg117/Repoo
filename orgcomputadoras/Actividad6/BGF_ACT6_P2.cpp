/*Brian De Jesus Gatelum Fierro
Matricula:373408
Patrones con cadenas
08/03/2025
BGF_ACT6_PE_.CPP
*/
#include "brian.h"
void patrones();
void patron1();
void patron2();
void patron3();
void patron4();
void patron5();
void patron6();
void patron7();

int main()
{
    patrones();
    return 0;
}

void patron1(char palabra[]) // listo
{
    printf("%s\n", palabra);
}
void patron2(char palabra[]) // listo
{
    for (int i = 0; palabra[i] != '\0'; i++)
    {
        printf("%c\n", palabra[i]);
    }
}
void patron3(char palabra[]) // listo
{
    for (int i = strlen(palabra) - 1; i >= 0; i--) // inicia desde el final
    {
        printf("%c\n", palabra[i]);
    }
}
void patron4(char palabra[]) // listo
{
    int len = strlen(palabra); // para la longitud
    for (int i = len; i > 0; i--)
    {
        printf("%.*s\n", i, palabra); // el * va quitando un caracter
    }
}
void patron5(char palabra[])
{
    int len = strlen(palabra);
    for (int i = 0; i < len; i++) // voltea la palabra
    {

        for (int j = len - 1; j >= i; j--) // imprime lo que quede
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
    }
}
void patron6(char palabra[]) // listo
{
    int len = strlen(palabra);
    for (int i = 0; i < len; i++) // revisa desde la primer letra a la ultima
    {
        printf("%s\n", palabra + i); // aumenta una letra
    }
}
void patron7(char palabra[])
{
    int len = strlen(palabra);
    for (int i = len; i > 0; i--) // empieza completa y reduce de 1 a 1 de manera inversa
    {
        for (int j = i - 1; j >= 0; j--)
        {
            printf("%c", palabra[j]);
        }
        printf("\n"); // si lo pongo en el otro for se imprime todo en una sola linea vertical
    }
}
void patrones()
{
    char palabra[15];
    printf("Dame una palabra para mostrarte sus diferentes patrones\n");
    my_gets(palabra, 15);
    printf("Patron 1:\n");
    patron1(palabra);
    printf("Patron 2\n");
    patron2(palabra);
    printf("Patron 3\n");
    patron3(palabra);
    printf("Patron 4\n");
    patron4(palabra);
    printf("Patron 5\n");
    patron5(palabra);
    printf("Patron 6\n");
    patron6(palabra);
    printf("Patron 7\n");
    patron7(palabra);
}

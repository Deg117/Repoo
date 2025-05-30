#include <stdio.h>
#include <string.h>

int main()
{
    char nombre[40];
    char marco;
    int i, longitud;

    printf("Dame tu nombre ");
    fgets(nombre, 40, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';// elimina el salto de pagina
    printf("Dame un caracter para el marco ");
    scanf("%c", &marco);

    longitud = strlen(nombre); // tamaño del nombre

    for (i = 0; i < longitud+2; i++) //primer linea de marco
    {
        printf("%c", marco);
    }
    printf("\n");
    printf("%c%s%c\n",marco, nombre, marco);

    for (i = 0; i < longitud+2; i++) // segunda linea del marco
    {
        printf("%c", marco);
    }
    printf("\n");

    return 0;
}

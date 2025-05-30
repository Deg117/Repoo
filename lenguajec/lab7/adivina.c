#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int n, n1, jugar = 1;

    srand(time(NULL));

    while (jugar)
    {
        n = rand() % 10 + 1;
        printf("Tengo un numero entre 1 y 10\n");
        printf("Puedes adivinar cual es?\n");
        
        do
        {
            printf("Escribe tu respuesta: ");
            scanf("%d", &n1);

            if (n1 < n)
                printf("Muy abajo. Intenta de nuevo.\n");
            else if (n1 > n)
                printf("Muy arriba. Intenta de nuevo.\n");
            else
                printf("Excelente Adivinaste el numero\n");

        } while (n1 != n);

        printf("Quieres jugar otra vez (1 para si, 0 para no)? ");
        scanf("%d", &jugar);
    }

    printf("Gracias por jugar\n");
    return 0;
}

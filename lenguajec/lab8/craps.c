#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Craps();

int main()
{
    int saldoBanco = 1000;
    int apuesta;
    int resultado, continuar;

    srand(time(NULL));

    printf("Tienes $%d en tu saldo.\n", saldoBanco);

    while (saldoBanco > 0)
    {
        int mensaje = rand() % 3;
        switch (mensaje)
        {
        case 0:
            printf("Ande, atrevase!\n");
            break;
        case 1:
            printf("Ya estas grande, ahora es el momento de arriesgarse\n");
            break;
        case 2:
            printf("Mm..., parece que va a la quiebra.\n");
            break;
        }

        do
        {
            printf("Introduce tu apuesta: ");
            scanf("%d", &apuesta);
            if (apuesta > saldoBanco || apuesta <= 0)
            {
                printf("Apuesta invalida. Solo tienes $%d\n", saldoBanco);
            }
        } while (apuesta > saldoBanco || apuesta <= 0);

        resultado = Craps();

        if (resultado == 1)
        {
            saldoBanco += apuesta;
            printf("¡Ganaste! Tu nuevo saldo es: $%d\n", saldoBanco);
        }
        else
        {
            saldoBanco -= apuesta;
            printf("Perdiste. Tu nuevo saldo es: $%d\n", saldoBanco);
            if (saldoBanco == 0)
            {
                printf("Lo siento. Su saldo se agotó.\n");
                break;
            }
        }

        printf("Quieres seguir jugando? (1 para si, 2 para no): ");
        scanf("%d", &continuar);
        if (continuar != 1)
            break;
    }

    return 0;
}

int Craps()
{
    int num1, num2, punto, tiro;
    num1 = rand() % 6 + 1;
    num2 = rand() % 6 + 1;
    tiro = num1 + num2;

    printf("El jugador tira %d + %d = %d\n", num1, num2, tiro);

    if (tiro == 7 || tiro == 11)
    {
        return 1; 
    }
    if (tiro == 2 || tiro == 3 || tiro == 12)
    {
        return 0; 
    }

    punto = tiro;
    printf("El punto es: %d\n", punto);

    while (1)
    {
        num1 = rand() % 6 + 1;
        num2 = rand() % 6 + 1;
        tiro = num1 + num2;

        printf("El jugador tira %d + %d = %d\n", num1, num2, tiro);

        if (tiro == punto)
        {
            return 1;
        }
        if (tiro == 7)
        {
            return 0;
        }
    }
}

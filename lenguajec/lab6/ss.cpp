/* Cuenta las calificaciones expresadas en letras */
#include <stdio.h>

/* la función main comienza la ejecución del programa */
int main()
{
    int calificacion; /* una calificación */
    int cuentaA = 0; /* número de As */
    int cuentaB = 0; /* número de Bs */
    int cuentaC = 0; /* número de Cs */
    int cuentaD = 0; /* número de Ds */
    int cuentaF = 0; /* número de Fs */

    printf( "Introduzca la letra que corresponde a la calificaci%cn.\n", 162 );
    printf( "Introduzca el car%ccter EOF(\"Ctrl+z\" y \"Enter\") para finalizar la entrada de datos.\n", 160);

    /* repite hasta que el usuario digita la secuencia de teclas de fin
    de archivo */
    while ( ( calificacion = getchar() ) != EOF ) {

        /* determina cuál calificación se introdujo */
        switch ( calificacion ) { /* switch anidado dentro del while */

            case 'A': /* la calificación es A */
            case 'a': /* o a */
                ++cuentaA; /* incrementa cuentaA */
                break; /* necesario para salir de switch */

            case 'B': /* la calificación es B */
            case 'b': /* o b */
                ++cuentaB; /* incrementa cuentaB */
                break; /* sale de switch */

            case 'C': /* la calificación es C */
            case 'c': /* o c */
                ++cuentaC; /* incrementa cuentaC */
                break; /* sale de switch */

            case 'D': /* la calificación es D */
            case 'd': /* o d */
                ++cuentaD; /* incrementa cuentaD */
                break; /* sale de switch */

            case 'F': /* la calificación es F */
            case 'f': /* o f */
                ++cuentaF; /* incrementa cuentaF */
                break; /* sale de switch */

            case '\n': /* ignora nuevas líneas, */
            case '\t': /* tabuladores, */
            case ' ': /* y espacios en la entrada */
                break; /* fin de switch */

            default: /* atrapa todos los demás caracteres */
                printf( "Introdujo una letra incorrecta." );
                printf( " Introduzca una nueva calificacion.\n" );
                break; /* opcional; de todas maneras saldrá del switch */
        } /* fin de switch */

    } /* fin de while */

    /* muestra el resumen de los resultados */
    printf( "\nLos totales por calificacion son:\n" );
    printf( "A: %d\n", cuentaA ); /* despliega el número de calificaciones A */
    printf( "B: %d\n", cuentaB ); /* despliega el número de calificaciones B */
    printf( "C: %d\n", cuentaC ); /* despliega el número de calificaciones C */
    printf( "D: %d\n", cuentaD ); /* despliega el número de calificaciones D */
    printf( "F: %d\n", cuentaF ); /* despliega el número de calificaciones F */

    return 0; /* indica terminación exitosa del programa */

} /* fin de la función main */

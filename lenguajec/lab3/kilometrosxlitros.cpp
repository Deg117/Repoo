/*pseudocodigo
problema:Kilometraje
Inicializar variables como float para medir de manera mas precisa los kilometor por litro
lit_utilizados
kil_recorridos
kil_por_litro
procedimiento
comenzamos pidiendo con un printf la cantidad de litros utilizados para despues usr un while el cual
nos servira para repetir el proceso hasta que se nos de un -1 el cual indica el fin de nuestro programa
dentro del while utilizare un if el cual me ayudara a saber si los litros utilizados son validos es decir diferentes de cero
una vez estos sean validos se hacen las operaciones para obtener los kilometros recorridos con ese tanque de gasolina
la cual sera nuestra distancia recorrida sobre nuestra cantidad de gasolina
finalizacion
utilizamos un printf para mostrar los kilometros conducidos con el tanque de gasolina.
fuera del ciclo while usamos un return 0 para poder cerrar nuestro int main.
*/

#include <stdio.h>

int main()

{
    float lit_utilizados, kil_recorridos, kilxlitro;
    while (lit_utilizados != -1)
    {
        printf("Introduzca los litros utilizados (-1 para finalizar): ");
        scanf("%f", &lit_utilizados);

        if (lit_utilizados == -1)
        {
            printf("Saliendo del programa.\n");
            break;
        }

        if (lit_utilizados < 0)
        {
            printf("Favor de ingresar los litros en un numero diferente de 0\n");
            continue;
        }

        printf("Introduzca los kilometros recorridos: ");
        scanf("%f", &kil_recorridos);

                kilxlitro = kil_recorridos / lit_utilizados;
        printf("Los kilometros recorridos por litro de este tanque fueron: %f\n", kilxlitro);
    }

    return 0;
}
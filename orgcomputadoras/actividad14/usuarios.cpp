#include "brian_act14.h"

int main()
{
    int op;
    Usu vector_usu[30];
    Usu registros;
    int j = 0;
    FILE *fb = fopen("registros.dll", "rb");
    /*if (fb)
    {
        cargar_archbin(vector_usu, inicializar());
        fclose(fb);
    }*/
    do
    {

        printf("1.-Agregar Usuario\n");
        printf("2.-Eliminar usuario\n");
        printf("3.-Modificar nivel\n");
        printf("4.-Quitar Estatus Bloqueado\n");
        printf("5.-Salir\n");
        op = validar(0, 5, "Dame un opcion\n");
        switch (op)
        {
        case 1:
            registros = agregar_usuario(vector_usu, j);
            vector_usu[j++] = registros;
            claves(registros, j);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            leer_archbin2(vector_usu, j);
            break;

        case 5:

            break;
        }
    } while (op != 5);
}

/*Brian De Jesus Gatelum Fierro
Matricula:373408
ACtividad 14
17/05/2025
BGF_ACT14_PE_.CPP
*/
#include "brian_act14.h"
// no lee niveles aun
int main()
{

    iniciar_sesion();
    if (nivel_usu == 0)
    {
        exit(0);
    }
    Twrkr vector_reg[inicializar()];
    char narchivo[50];
    Twrkr reg;
    Twrkr vector;
    int op, opc, ordenado = 0;
    int j = cargar_archbin(vector_reg, 0);
    int arch = 0, band = 0, elim = 0, llena = 0;
    FILE *fb = fopen("datos.dat", "rb");
    if (fb)
    {
        cargar_archbin(vector_reg, inicializar());
        fclose(fb);
        band = 1;
        llena = 1;
    }
    do
    {
        printf("1 Agregar \n");
        printf("2 Eliminar\n");
        printf("3 Buscar\n");
        printf("4 Ordenar\n");
        printf("5 Mostrar del binario\n");
        printf("6 Mostrar Registros ordenados\n");
        printf("7 generar archivo de texto\n");
        printf("8 Empaquetar Binario\n");
        printf("9 Crear usuario\n");
        printf("0.-Salir\n");
        op = validar(0, 9, "Dame una opcion\n");
        switch (op)
        {
        case 1:
            if (nivel_usu == 2 || nivel_usu == 3)
            {
                if (j < inicializar())
                {

                    reg = agregar_aleato(vector_reg);
                    vector_reg[j++] = reg;
                    printf("Todo bien\n"); // para que sepa que se agregaron bien
                    system("PAUSE");
                    system("CLS");
                }
                else
                {
                    printf("vector lleno\n");
                }

                band = 1;
                llena = 1;
                ordenado = 0;
            }
            else
            {
                printf("Acceso denegado, te faltan permisos\n");
                system("pause");
                system("CLS");
            }
            break;
        case 2:
            if (nivel_usu == 2 || nivel_usu == 3)

            {

                if (band)
                {
                    do
                    {
                        elimina_reg(vector_reg, j);
                        opc = validar(0, 1, "Quieres continuar borrando? \n(1 para si, 0 para no)\n");
                        elim = 1;
                        system("CLS");
                    } while (opc != 0);
                }
                else
                {
                    printf("Agrega Trabajadores primero si no que eliminas?\n"); // recordatorio de que esta vacio
                    system("PAUSE");
                    system("CLS");
                }
            }
            break;
        case 3:
            if (nivel_usu >= 1)
            {
                if (band == 0)
                {
                    printf("Agrega algo si no que buscas...\n"); // otro mensajito
                    system("PAUSE");
                    system("CLS");
                }
                else
                {
                    if (ordenado == 0)
                    {
                        printf("Busqueda secuencial\n:");
                        busqueda_secuencial(vector_reg, j);
                    }
                    else
                    {
                        printf("Busqueda Binaria\n:");
                        busqueda_bin(vector_reg, j);
                    }
                }
            }
            break;
        case 4:
            if (nivel_usu >= 1)
            {
                if (llena == 0)
                {
                    printf("Agrega algo si no que ordenas...\n"); // mensajito amable
                    system("PAUSE");
                    system("CLS");
                }
                else
                {
                    if (ordenado == 0)
                    {
                        if (j <= 10)
                        {
                            burbuja(vector_reg, j);
                            printf("Se uso el metodo de burbuja\n");
                        }
                        if (j > 10 && j < 20)
                        {
                            seleccion(vector_reg, j);
                            printf("se utilizo el metodo de seleccion\n");
                        }
                        if (j >= 20)
                        {
                            insercion(vector_reg, j);
                            printf("se utilizo el metodo de insercion\n");
                        }
                    }
                    else
                    {
                        printf("Ya se ordeno no te lo puedo ordenar mas\n"); // por si no agrego mas datos y quiere seguir ordenando
                        system("PAUSE");
                        system("CLS");
                    }
                    ordenado = 1;
                }
            }
            break;
        case 5:
            if (nivel_usu >= 1)
            {
                if (band)
                {
                    imp_vect_reg(vector_reg, j);
                    system("PAUSE");
                    system("CLS");
                }
                else
                {
                    printf("Agrega Trabajadores primero si no que te muestro...\n");
                    system("PAUSE");
                    system("CLS");
                }
            }
            break;
        case 6:
            if (nivel_usu >= 1)
            {
                if (ordenado)
                {
                    imp_vect_orde(vector_reg, j);
                    system("PAUSE");
                    system("CLS");
                }
                else
                {
                    printf("Ordena primero ...\n");
                    system("PAUSE");
                    system("CLS");
                }
            }
            break;
        case 7:
            if (nivel_usu == 3)
            {
                if (band)
                {
                    printf("Dime como vas a nombrar el archivo\n");
                    my_gets(narchivo, 50);
                    agregartxt(narchivo);
                    generar_arch(vector_reg, j, narchivo);
                    system("CLS");
                    printf("Todo chido\n");
                    arch = 1;
                }
                else
                {
                    printf("agrega Trabajadores si no el archivo estara en blanco\n"); // recordatorio de que esta vacio
                }
            }
            break;
        case 8:
            if (nivel_usu == 3)
            {
                if (band)
                {
                    generar_archbin(vector_reg, j);
                    system("PAUSE");
                    system("CLS");
                }
                else
                {
                    printf("Agrega unos registros primero\n");
                    system("PAUSE");
                    system("CLS");
                }
            }
            break;
        case 9:
            if (nivel_usu == 3)
            {
                system(".\\usuarios.exe");
            }
            break;
        case 0:
            printf("saliendo\n");
            break;
        }
    } while (op != 0);

    return 0;
}

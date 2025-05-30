#include <stdio.h>

enum estado_sistema{


    APAGADO,
    ENCENDIDO,
    EN_PAUSA,
    EN_ERROR
};




int maint()
{
enum estado_sistema estado_actual =ENCENDIDO;
if (estado_actual== ENCENDIDO)
{
    printf("El sistema est%c encendido",160);
}
else
{
    printf("El sistema esta%c apagado",160);
}
return 0;
}
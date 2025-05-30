/*Brian De Jesus Gatelum Fierro
Matricula:373408
Curp
23/03/2025---04/04/2025
BGF_ACT8_PE_.CPP
*/
#include "curp3.h"
#include <windows.h>
int main()
{
    int op;
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
    do
    {
        principal();
        op=validar(0,1,"Continuar generando curp?\n1-si  0-no\n");
    } while (op!=0);

    return 0;
}

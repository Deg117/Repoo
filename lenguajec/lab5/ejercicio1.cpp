#include <stdio.h>

int main()
{
 int x,y,i,j;
printf("Introduzca dos enteros entre 1 y 20\n");
scanf("%d%d",&x,&y);
for (i=1; i<=y; i++)  /*cuenta de 1 a 10*/
{
    for(j=1; j<=x; j++) /*cuenta de 1 a x*/
    {
    printf ("@");
    }
    printf("\n");
}


    return 0;
}
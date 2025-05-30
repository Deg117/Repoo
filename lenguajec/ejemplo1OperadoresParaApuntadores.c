/*
Uso de los operadores & y * */
#include <stdio.h>

int main()
{
    int a; /* a es un entero */
    int *ptrA; /* ptrA es un apuntador a un entero */

    printf( "El valor de a es: %d" //, a
    "\nEl valor de ptrA usando el operador de indirecci%cn * es: %d" //, 162, *ptrA
    "\nLa direcci%cn de &a es: %p" //, 162, &a
    "\nEl valor de ptrA utilizando el operador de direcci%cn & es: %p" //, 162, &ptrA
    "\nEl valor de ptrA sin utilizar el operador de direcci%cn & es: %p" //, 162, ptrA
    , a, 162, *ptrA, 162, &a, 162, &ptrA, 162, ptrA );

    a = 7;
    ptrA = &a; /* ptrA toma la dirección de a */

    printf( "\n\nEl valor de a es: %d" //, a
    "\nEl valor de ptrA usando el operador de indirecci%cn * es: %d" //, 162, *ptrA
    "\nLa direcci%cn de &a es: %p" //, 162, &a
    "\nEl valor de ptrA utilizando el operador de direcci%cn & es: %p" //, 162, &ptrA
    "\nEl valor de ptrA sin utilizar el operador de direcci%cn & es: %p" //, 162, ptrA
    , a, 162, *ptrA, 162, &a, 162, &ptrA, 162, ptrA );


    printf( "\n\nLa direcci%cn de a es: %p"
    "\nEl valor de ptrA es: %p", 162, &a, ptrA );

    printf( "\n\nEl valor de a es: %d"
    "\nEl valor de *ptrA es: %d", a, *ptrA );

    printf( "\n\nMuestra de que * y & son complementos "
    "uno del otro\n&*ptrA = %p"
    "\n*&ptrA = %p\n\n", &*ptrA, *&ptrA );

    return 0; /* indica terminación exitosa */

} /* fin de main */


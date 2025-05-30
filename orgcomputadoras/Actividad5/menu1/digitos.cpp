#include <stdio.h>
void digitos(void)
{
    int num, i = 0;
    printf("Dame un numero entero y te dire cuantos digitos tiene\n");
    scanf("%d", &num);

    do
    {
        num = num / 10;
        i++;
    } while (num != 0);

    printf("Tiene %d digitos\n", i);
}
int main()
{
    digitos();
    return 0;
}

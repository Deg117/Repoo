// Brian de Jesus Gastelum Fierro mat:373408
// Cálculo del Consumo de Agua
// 14-feb-2025
// BGF_ACT3.CPP
#include <stdio.h>

int main()
{
    float consumo, subtotal, iva, total;
    printf("Dame el consumo del mes en metros cubicos\n");
    scanf("%f", &consumo);

    if (consumo >= 0 && consumo <= 4)
    {
        subtotal = 50.00;
    }
    else if (consumo >= 5 && consumo <= 15)
    {
        subtotal = 50.00 + (consumo - 4) * 8.00;
    }
    else if (consumo >= 16 && consumo <= 50)
    {
        subtotal = 50.00 + (15 - 4) * 8.00 + (consumo - 15) * 10.00;
    }
    else
    {
        subtotal = 50.00 + (15 - 4) * 8.00 + (50 - 15) * 10.00 + (consumo - 50) * 11.00;
    }

    iva = subtotal * 0.16;
    total = subtotal + iva;

    printf("El subtotal es %.2f\nEl iva es %.2f\nEl total es %.2f\n", subtotal, iva, total);

    return 0;
}
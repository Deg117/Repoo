#include <stdio.h>
#include <math.h>
int main() {
    float area = 10096.303711;
    float pi = 3.14159;
    float radio;
    radio = sqrt(area / pi);
    printf("El radio del círculo es: %f\n", radio);
    return 0;
}

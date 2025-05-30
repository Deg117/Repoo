// Gastelum Fierro brian de Jesus

#include <stdio.h>
int main()
{
    int ninici, nfinal, n;
    printf("Dame el valor inicial\n");
    scanf("%d", &ninici);
    printf("Dame el valor final\n");
    scanf("%d", &nfinal);

    while (ninici <= 0)
    {
        printf("");
    }
  
    n = ninici;
    while (n < nfinal) {
        printf("%d, ", n);
        n++;
    }

    printf("y %d.\n", nfinal);

    
    return 0;
}
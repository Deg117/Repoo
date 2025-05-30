#include <stdio.h>

int main() {
    int i;
    for (i = 1; i <= 300000000; i++) {
        if (i % 100000000 == 0) { 
            printf("%d\n", i);   
        }
    }
    
    printf("Fin hasta 300,000,000.\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        printf("Missing parameters...\n");
        return 0;
    }
    time_t p_seconds = 0;
    time_t ini, actual;
    int multiplier = 1;
    int narg,n;
    if (argc == 3)
    {
        if (!isdigit(argv[1][0]))
        {
            printf("First parameter must be a number...\n");
            return 0;
        }
        sscanf(argv[1], "%d", &n);
        p_seconds = (time_t)n;
    }
    printf("Alarm set...\n");
    actual = ini = time(0);
    while ((actual - ini) < p_seconds)
    {
        actual = time(0);
    }
    while (1)
    {
        printf("%s %s %s", argv[argc - 1], argv[argc - 1], argv[argc-1]);
        ini = time(0);
        while ((time(0) - ini) <= 3);
    }
    return 0;
}

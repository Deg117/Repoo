#include <stdio.h>

int maximo(int x, int y, int z);


int main()
{
int num1,num2,num3;

printf("Introduzca tres entereros");
scanf("%d%d%d",&num1,&num2,num3);
printf("El maximo es:"maximo(x,y,x));

}

int maximo(int x, int y, int z)
{
    int max = y;
    {
        if (z > y)
        {
            max=z;
        }
       return max;
    }
}

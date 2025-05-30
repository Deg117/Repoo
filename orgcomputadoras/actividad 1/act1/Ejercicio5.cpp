#include <stdio.h>
int main()
{
 int ht;
 float sh,sals,he=0;
 printf("Dame las horas trabajadas en la semana");
 scanf("%d",&ht);
 printf("Dame el salario por hora");
 scanf("%f",&sh);
 if (ht<= 40) {
  sals = ht*sh;
  } else {
  he=ht-40;
  if (he<=9) {
  sals=(40*sh)+(he*sh*2);
  } else {
   sals=(40*sh)+(9*sh*2)+((he-9)*sh*3);
  }
  }
  printf("El salarioes %f\n",sals);
  return 0;
}
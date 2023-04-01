#include <stdio.h>

long DecimalToBinary(int num){
   long bno=0,rem,f=1;
   while(num != 0){
      rem = num % 2;
      bno = bno + rem * f;
      f *= 10;
     num/=2;
   }
   return bno;
}
int main()
{
   long n,x;
   printf("Please enter the number: ");
   scanf("%ld",&n);
 x =  DecimalToBinary(n);
 printf("Binary Number: ");
printf("%ld\n",x);
printf("To change it in vertical way:\n");
int i=0;
while(x !=0)
{
    printf("%ld\n",x%10);
x/=10;
i++;
}

    return 0;
}

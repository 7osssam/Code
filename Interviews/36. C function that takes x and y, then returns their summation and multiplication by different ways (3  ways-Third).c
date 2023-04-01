#include <stdio.h>
int Addition(int x, int y)
{
   while(y != 0)
   {
       int carry = x & y;
       x = x ^ y;
       y = carry << 1;
   }
   return x;
}
int main()
{
    int num1,num2,r;
    printf("Enter first number: ");
    scanf("%d",&num1);
    printf("Enter second number: ");
    scanf("%d",&num2);
    r = Addition(num1,num2);
    printf("Result = %d",r);
    return 0;
}

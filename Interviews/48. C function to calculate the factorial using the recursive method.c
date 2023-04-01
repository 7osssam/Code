#include <stdio.h>
int factorial(int num)
{
    if((num -1) !=0)
    {
    return num * factorial(num - 1);
    }
}
int main()
{
   int n,x;
   printf("Please enter the number: ");
   scanf("%d",&n);
  x = factorial(n);
  printf("Factorial = %d",x);
    return 0;
}

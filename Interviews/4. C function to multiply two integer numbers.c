#include <stdio.h>
long Multiply(int num1,int num2)
{
  long result;
  result =(long ) num1 * (long )num2;
  return result;
}
int main()
{
  long x;
  int n1,n2;

    printf("Please enter first number: ");
    scanf("%d",&n1);
    printf("Please enter second number: ");
    scanf("%d",&n2);
    x = Multiply(n1,n2);
    printf("Multiply = %ld",x);
    return 0;
}

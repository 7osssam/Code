#include <stdio.h>
int Sum(int num)
{
    int sum=0,i=0;
    while(num !=0)
    {
    sum+= (num%10);
    num/=10;
    }
  return sum;
}
int main()
{
    int n,x;
    printf("Please enter the number: ");
    scanf("%d",&n);
   x = Sum(n);
   printf("Sum = %d",x);
 
    return 0;
}

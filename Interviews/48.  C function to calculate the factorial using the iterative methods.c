#include <stdio.h>
void factorial(int num)
{
    int result =1 ;
   while(num != 0)
   {
       result*=num;
       num--;
   }
   printf("Factorial = %d",result);
}
int main()
{
   int n,x;
   printf("Please enter the number: ");
   scanf("%d",&n);
  factorial(n);
  
    return 0;
}

#include <stdio.h>
int Addition(int x, int y)
{
   int i,result;
   if(x<y)
   {
       result = x;
       for(int i=0; i<y; i++)
       {
           result+=1;
       }
   }
   else if(y<x)
   {
       result = y;
        for(int i=0; i<x; i++)
       {
           result+=1;
       }
   }
    return result;
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

#include <stdio.h>

void SwapAddSub(int num1, int num2)
{
  int temp;
  temp = num1+num2;
  num1 = temp - num1;
  num2 = temp - num1;
  printf("First number = %d\nSecond number = %d",num1,num2);
}
int main()
{
   int x,y;
   printf("Please enter the first number: ");
   scanf("%d",&x);
   printf("Please enter the second number: ");
   scanf("%d",&y);
   SwapAddSub(x,y);
    return 0;
}

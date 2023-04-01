#include <stdio.h>

void Swap(int *num1, int *num2)
{
   int temp;
   temp = *num1;
   *num1 = *num2;
   *num2 = temp;
   printf("num1 = %d\nnum2 = %d",*num1,*num2);
}
int main()
{
   int x,y;
   printf("Please enter the first number: ");
   scanf("%d",&x);
   printf("Please enter the second number: ");
   scanf("%d",&y);
    Swap(&x,&y);
    
    return 0;
}

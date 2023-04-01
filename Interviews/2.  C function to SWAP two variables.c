#include <stdio.h>
void SwapNumbers(int num1, int num2)
{
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
    printf("First number: %d\nSecond number: %d\n",num1,num2);
}
int main()
{
   int n1,n2;
   printf("Enter first number: ");
   scanf("%d",&n1);
   printf("Enter second number: ");
   scanf("%d",&n2);
   SwapNumbers(n1,n2);

    return 0;
}

#include <stdio.h>
void SWAP(int num1, int num2)
{
  
   num1 = num1 ^ num2;
   num2 = num1 ^ num2;
   num1 = num1 ^ num2;
   printf("First number = %d\nSecond number = %d",num1,num2);
  
}
int main()
{
   int n1,n2;
   printf("Please enter the first number: ");
   scanf("%d",&n1);
   printf("Please enter the second number: ");
   scanf("%d",&n2);
   SWAP(n1,n2);
   

   
    return 0;
}

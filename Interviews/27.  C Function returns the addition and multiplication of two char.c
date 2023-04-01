#include <stdio.h>
int Add_Mul(char x , char y, int *add, int*mul)
{
  
   *add = x + y;
   *mul = x*y;
   

  
}
int main()
{
  int num1,num2,addition,multiply;
  printf("Please enter the first number: ");
  scanf("%d",&num1);
  printf("Please enter the second number: ");
  scanf("%d",&num2);
  
   Add_Mul(num1,num2,&addition,&multiply);
   printf("Addition = %d\nMultiply = %d",addition,multiply);

   
    return 0;
}

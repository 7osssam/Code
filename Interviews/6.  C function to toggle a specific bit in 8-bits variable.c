#include <stdio.h>

int Toggle(char Reg, int bit)
{
    Reg ^=(1<<bit);
    return Reg;
}
int main()
{
    char r,x;
    int b;
   printf("Please enter the register: ");
   scanf("%c",&r);
   printf("Please enter bit no: ");
   scanf("%d",&b);
   x = Toggle(r,b);
   printf("After toggle = %c",x);
    return 0;
}

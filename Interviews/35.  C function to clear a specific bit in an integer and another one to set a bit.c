#include <stdio.h>
void ClearBit(int reg, int bit)
{
    reg &= (~(1<<bit));
    printf("%d",reg);
}
void SetBit(int reg, int bit)
{
    reg |=(1<<bit);
    printf("%d",reg);
}
int main()
{
   int n,b;
   printf("Please enter the number: ");
   scanf("%d",&n);
   printf("Please enter the bit: ");
   scanf("%d",&b);
  // ClearBit(n,b);
 SetBit(n,b);
    return 0;
}

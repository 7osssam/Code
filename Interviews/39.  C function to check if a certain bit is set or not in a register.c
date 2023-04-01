#include <stdio.h>
#define GET_BIT(REG,BIT)  ((REG>>BIT)&0x01)
void CheckBit(int reg, int bit )
{
    int *ptr = &reg;
  *ptr = GET_BIT(reg,bit);
  if(*ptr == 1)
  {
     printf("Bit is set");
  }
  else if(*ptr == 0)
  {
      printf("Bit is cleared");
  }
}
int main()
{
    int num,b;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("Enter bit no: ");
    scanf("%d",&b);
    CheckBit(num,b);

   
    
    return 0;
}

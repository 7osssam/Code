#include <stdio.h>
void SWAPNum(int num)
{
  int i=0,reserved=0;
  while(num!=0)
  {
     
      reserved = reserved*10+ num%10;
      num/=10;
      i++;
  }
  
   printf("Num will be = %d",reserved);
 }
  

int main()
{
    int n;
   printf("Please enter number: ");
   scanf("%d",&n);
   SWAPNum( n);
    return 0;
}

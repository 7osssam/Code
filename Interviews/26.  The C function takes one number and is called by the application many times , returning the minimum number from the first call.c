#include <stdio.h>
unsigned int MIN_TEMP(signed int temp)
{
    static signed int min;
   static signed int flag =0;
   if(flag == 0)
   {
       min = temp;
       flag =1;
   }
   else
   {
       if(temp<min)
       {
           min = temp;
        
       }
   }
  return min;  
}
int main()
{
    int t1,t2,t3;
t1 = MIN_TEMP(5);
t2 = MIN_TEMP(10);
t3 = MIN_TEMP(15);
printf("%d %d %d",t1,t2,t3);
    return 0;
}

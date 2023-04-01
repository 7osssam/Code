#include <stdio.h>
void Reverse(int num)
{
    int rev,i;
    for(i=0; i<sizeof(char)*8; i++)
    {
   
           rev<<=1;
           if(num & 1)
           {
               rev^=1;
              
           }
            num>>=1;
    }     
  
  printf("Reversed number = %d",rev);
}
int main()
{
    int n,x;
    printf("Please enter the number: ");
    scanf("%d",&n);
   Reverse(n);
 
 
    return 0;
}

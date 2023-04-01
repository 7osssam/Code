#include <stdio.h>
void PRIME(int num)
{
    int j,flag=0;

  
       if(num==0 || num== 1)
       {
           flag=1;
          
       }
       for(j=2; j<=num/2; j++)
       {
           if(num%j == 0)
           {
               flag =1;
               break;
           }
           else
           {
               flag = 0;
           }
       }
    
     
    
       if(flag == 0)
       {
           printf("The number is prime");
       }
       else
       {
           printf("The number is not prime");
       }
    
}
int main()
{
    int n;
    printf("Please enter the number: ");
    scanf("%d",&n);
    PRIME(n);

    return 0;
}

#include <stdio.h>
void PRIME(int num1, int num2)
{
    int i,j,flag=0;
    printf("Prime numbers are: ");
    for(i=num1; i<=num2; i++)
    {
       if(i==0 || i== 1)
       {
           flag=1;
          
       }
       for(j=2; j<=(i/2); j++)
       {
          
           if(i%j == 0)
           {
              flag=1;
              break;
           }
       }
       if(flag == 0)
       {
           printf("%d ",i);
       }
       else
       {
           flag = 0;
       }
     
    }
    
}
int main()
{
    int n1,n2;
    printf("Please enter two number: ");
    scanf("%d %d",&n1,&n2);
    PRIME(n1,n2);

    return 0;
}

#include <stdio.h>
void ConsecutiveOnes(unsigned int num)
{
    int max=0,i=0,count=0;
    for(i=0; i<sizeof(int)*8; i++)
    {
        if((num>>i) & 1)
        {
            count++;
            if(count>max)
            {
                max = count;
            }
          
        }
        else
        {
            count=0;
        }
    }
    printf("%d",max);
    
}
int main()
{
   int n;
   printf("Please enter the number: ");
   scanf("%d",&n);
   ConsecutiveOnes(n);
    return 0;
}

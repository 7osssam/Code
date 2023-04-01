
#include <stdio.h>
#define SIZE 10
int ArrayNumbers(int *arr)
{
    int i,sum=0;
    for(i=0; i<SIZE; i++)
    {
        if(arr[i]>=0 && arr[i]<=9)
        {
            sum+=arr[i];
            
        }
    }
    if(sum == 45)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
   
    int i,result,arr[SIZE];
    printf("Enter Array numbers: ");
    for(i=0; i<SIZE; i++)
    {
        scanf("%d",&arr[i]);
    }
   result = ArrayNumbers(arr);
   if(result == 1)
   {
       printf("True");
   }
   else
   {
       printf("False");
   }
    
    return 0;
}

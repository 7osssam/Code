#include <stdio.h>

void UniqueNum(int *arr,int size)
{
    int i,j,count=0;
    for(i=0; i<size; i++)
    {
        count=0;
        for(j=0; j<size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                
            }
           
    
        }
        if(count == 1)
        {
          printf("%d",arr[i]);
        } 
    }
  
}
int main()
{
   int n,size,i;
   printf("Please enter the size of array: ");
   scanf("%d",&size);
   int arr[size];
   printf("Please enter elements of array: ");
   for(i=0; i<size; i++)
   {
       scanf("%d",&arr[i]);
   }
    UniqueNum(arr,size);

    
    return 0;
}

#include <stdio.h>
void BubbleSorting(int *arr, int size)
{
      int temp;
    int i=0,j=0,flag=0;
    for(j=0; j<size; j++)
    {
        flag=1;
        for(i=0; i<size-j-1; i++)
        {
            if(arr[i]> arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag=0;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
   int s,i;
   printf("Enter size of array: ");
   scanf("%d",&s);
   int arr[s];
   printf("Enter elements of array: ");
   for(i=0; i<s; i++)
   {
       scanf("%d",&arr[i]);
   }
   BubbleSorting(arr,s);
    return 0;
}

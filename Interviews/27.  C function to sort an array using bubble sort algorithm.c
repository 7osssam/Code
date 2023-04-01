#include <stdio.h>
void BubbleSorting(int *arr, int size)
{
    int i,j,flag=0;;
    for(j=0; j<size; j++)
    {
        flag = 1;
        for(i=0; i<size-j-1; i++)
        {
        if(arr[i]>arr[i+1])
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            flag = 0;
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
  int s,i=0;
  printf("Please enter size of array: ");
  scanf("%d",&s);
  int arr[s];
  printf("Enter elements of array: ");
  for(i=0; i<s; i++)
  {
    scanf("%d",&arr[i]);  
  }
  BubbleSorting(arr, s);
 
 
    return 0;
}

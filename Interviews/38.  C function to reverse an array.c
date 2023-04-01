#include <stdio.h>
void ReverseArray(int *arr, int size)
{
  int i;
  printf("Reversed Array: ");
  for(i=0; i<size; i++)
  {
      printf("%d ",arr[size-1-i]);
  }
}
int main()
{
    int i,s;
    printf("Please enter size of array: ");
    scanf("%d",&s);
    int arr[s];
    printf("Enter elements of first array: ");
    for(i=0; i<s; i++)
    {
        scanf("%d",&arr[i]);
    }

     ReverseArray(arr,s);
    
    return 0;
}

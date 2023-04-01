#include <stdio.h>
void MIN_MAX(int *arr, int size)
{
    int max=0,min=arr[0],i=0;
    for(i=0; i<size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        if(arr[i]< min)
        {
            min = arr[i];
        }
    }
    printf("Max = %d\nMin = %d",max,min);
}

int main ()
{
  int i=0,s;
  printf("Please enter size of array: ");
  scanf("%d",&s);
  int arr[s];
  printf("Enter elements of the array: ");
  for(i=0; i<s; i++)
  {
      scanf("%d",&arr[i]);
  }
  MIN_MAX(arr,s);
    
  return 0;
}

#include <stdio.h>
void RemoveDuplication(int *arr,int size)
{
    int i=0,j=0;
    for(i=0; i<size; i++)
    {
        if(arr[i] != -1)
        {
           for(j=i+1; j<size; j++)
          {
            if(arr[i] == arr[j])
            {
                arr[j] = -1;
            }
          }
        }
    }
    for(i=0; i<size; i++)
    {
        if(arr[i] != -1)
        {
        printf("%d ",arr[i]);
        }
    }
}
int main()
{
  int s,i;
  printf("Please enter the size of array: ");
  scanf("%d",&s);
  int arr[s];
  printf("Please enter elements of array: ");
  for(i=0; i<s; i++)
  {
     scanf("%d",&arr[i]);
  }
  RemoveDuplication(arr,s);
return 0;
}

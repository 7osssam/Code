#include <stdio.h>
int SWAP(int *arr1, int *arr2,int size)
{
  int i;
  for(i=0; i<size; i++)
  {
      int temp;
      temp = arr1[i];
      arr1[i] = arr2[size-i-1];
      arr2[size-i-1] = temp;
      
  }
  printf("Array1: ");
  for(i=0; i<size; i++)
  {
      printf("%d ",arr1[i]);
  }
    printf("\nArray2: ");
  for(i=0; i<size; i++)
  {
      printf("%d ",arr2[i]);
  }
}
int main()
{
    int i,s;
    printf("Please enter size of array: ");
    scanf("%d",&s);
    int arr1[s],arr2[s];
    printf("Enter elements of first array: ");
    for(i=0; i<s; i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter elements of second array: ");
       for(i=0; i<s; i++)
    {
        scanf("%d",&arr2[i]);
    }
    SWAP(arr1,arr2,s);
    
    return 0;
}

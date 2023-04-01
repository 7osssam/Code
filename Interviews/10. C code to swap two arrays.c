#include <stdio.h>
void SwapArray(int *arr1, int*arr2, int size)
{
  int temp,i;
  for(i=0; i<size; i++)
  {
      temp = arr1[i];
      arr1[i] = arr2[i];
      arr2[i] = temp;
  }
}
int main()
{
    int i,s;
    printf("Please enter size of array: ");
    scanf("%d", &s);
    int arr1[s],arr2[s];
    printf("Please enter the first array elements: ");
    for(i=0; i<s; i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Please enter the second array elements: ");
    for(i=0; i<s; i++)
    {
        scanf("%d",&arr2[i]);
    }
   SwapArray(arr1,arr2,s);
   printf("The first array: ");
   for(i=0; i<s; i++)
   {
       printf("%d ",arr1[i]);
   }
   printf("\nThe second array: ");
   for(i=0; i<s; i++)
   {
       printf("%d ",arr2[i]);
   }
    return 0;
}

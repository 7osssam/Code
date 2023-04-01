#include <stdio.h>
void swap(int *arr1, int *arr2, int size)
{
    int i,temp;
    for(i=0; i<size; i++)
    {
        temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
    printf("Elements of array1: ");
    for(i=0; i<size; i++)
    {
        printf("%d ",arr1[i]);
    }
     printf("\nElements of array2: ");
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
   printf("Please enter elements of array1: ");
   for(i=0; i<s; i++)
   {
       scanf("%d",&arr1[i]);
   }
   printf("Please enter elements of array2: ");
      for(i=0; i<s; i++)
   {
       scanf("%d",&arr2[i]);
   }
   swap(arr1,arr2, s);
    return 0;
}

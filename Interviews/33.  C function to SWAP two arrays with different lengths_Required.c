#include <stdio.h>
void swap(int *arr1, int *arr2, int size1,int size2)
{
    int i;
    if(size1> size2)
    {
      
       for(i=0; i<size2; i++)
       {
           arr1[i] = arr1[i]^arr2[i];
           arr2[i] = arr1[i]^arr2[i];
           arr1[i] = arr1[i]^arr2[i];
       }
         printf("Elements of array1: ");
      for(i=0; i<size1; i++)
      {
          printf("%d ",arr1[i]);
      }
         printf("\nElements of array2: ");
         for(i=0; i<size2; i++)
        {
           printf("%d ",arr2[i]);
        }
    }
    else if(size2>size1)
    {
        for(i=0; i<size1; i++)
       {
           arr1[i] = arr1[i]^arr2[i];
           arr2[i] = arr1[i]^arr2[i];
           arr1[i] = arr1[i]^arr2[i];
       }
     
     
     printf("Elements of array1: ");
      for(i=0; i<size1; i++)
      {
          printf("%d ",arr1[i]);
      }
         printf("\nElements of array2: ");
         for(i=0; i<size2; i++)
        {
           printf("%d ",arr2[i]);
        }
    }
  
   
}
int main()
{
   int i,s1,s2;
   printf("Please enter size of array1: ");
   scanf("%d",&s1);
   int arr1[s1];
   printf("Please enter elements of array1: ");
   for(i=0; i<s1; i++)
   {
       scanf("%d",&arr1[i]);
   }
   printf("Please enter size of array2: ");
   scanf("%d",&s2);
   int arr2[s2];
   printf("Please enter elements of array2: ");
      for(i=0; i<s2; i++)
   {
       scanf("%d",&arr2[i]);
   }
   swap(arr1,arr2, s1,s2);
    return 0;
}

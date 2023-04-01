#include <stdio.h>
void MergeArray(int *arr1, int *arr2, int size1,int size2)
{
    int size = size1+size2;
  int arr3[size],i,j=0;
    if(size1<size2)
    {
      for(i=size1; i<=size2; i++)
      {
          arr1[i] = -1;
      }
    }
    else if(size2 < size1)
    {
        for(i=size2; i<size1; i++)
        {
            arr2[i] = -1;
        }
    }
  for(i=0; i<size;i+=2)
  {
      arr3[i] = arr1[j];
      arr3[i+1] = arr2[j];
  
     j++;
  }

if(size1>size2)
{
  printf("Elements of array3: ");
  for(i=0; i<size+(size1-size2); i++)
  {
      if(arr3[i] != -1)
      {
         printf("%d ",arr3[i]);
      }
  }
}
else
{
     printf("Elements of array3: ");
  for(i=0; i<size+(size2-size1); i++)
  {
      if(arr3[i] != -1)
      {
         printf("%d ",arr3[i]);
      }
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
   MergeArray(arr1,arr2, s1,s2);
    return 0;
}

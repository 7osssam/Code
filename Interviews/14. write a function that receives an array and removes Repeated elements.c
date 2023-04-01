#include <stdio.h>
void BubbleSorting(int *arr, int size)
{
    int flag=0,i=0,j=0,temp;
    for(j=0; j<size; j++)
    {
       for(i=0;i<size-j-1; i++)
       {
           if(arr[i+1]>arr[i])
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
    
}
int RemoveDuplication(int *arr, int n)
{
    int j=0,i=0,temp[n];
   if(n == 0 || n == 1)
   {
       return n;
   }
   // If current element is not equal to next element
    // then store that current element
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];
    }
  
    // Store the last element as whether it is unique or
    // repeated, it hasn't stored previously
    temp[j++] = arr[n - 1];
  
    // Modify original array
    for (int i = 0; i < j; i++)
    {
        arr[i] = temp[i];
    }
  
    return j;
}
int main()
{
    int s,i=0;
    int arr[] = {5,4,3,2,3,1,7,7};
    s = sizeof(arr)/sizeof(arr[0]);
    BubbleSorting(arr,s);
    printf("Bubble Sorting array: ");
     for(i=0; i<s; i++)
    {
       printf("%d ",arr[i]);
    }
    
    printf("\nRemove Duplication array: ");
     s = RemoveDuplication(arr,s);
     for(i=0; i<s; i++)
    {
       printf("%d ",arr[i]);
    }
    return 0;
}

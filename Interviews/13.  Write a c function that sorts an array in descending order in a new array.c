#include <stdio.h>

void SortArrayInNewOne(int *arr1, int size)
{ 
    int i,j,temp,arr2[size],flag=0;
    for(j=0; j<size; j++)
    {
        flag =1;
        for(i=0; i<size-j-1; i++)
        {
            if(arr1[i]<arr1[i+1])
            {
                temp = arr1[i];
                arr1[i] = arr1[i+1];
                arr1[i+1] = temp;
                flag=0;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
    printf("Second array: ");
    for(i=0; i<size; i++)
    {
        arr2[i] = arr1[i];
        printf("%d ",arr2[i]);
    }
  
}
int main()
{
   int i,s;
   printf("Please enter the size of array: ");
   scanf("%d",&s);
   int arr1[s],arr[s];
   printf("Elements of first array: ");
   for(i=0; i<s; i++)
   {
       scanf("%d",&arr1[i]);
   }
   SortArrayInNewOne(arr1,s);
    return 0;
}

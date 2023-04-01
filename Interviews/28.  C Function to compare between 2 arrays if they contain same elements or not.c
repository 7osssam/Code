#include <stdio.h>
void Compare(int *arr1, int *arr2, int size)
{
    int i,flag=0;
    for(i=0; i<size; i++)
    {
        if(arr1[i] == arr2[i])
        {
            flag = 0;
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("The two arrays are equal");
    }
    else
    {
        printf("The two arrays are not equal");
    }
}

int main()
{
  int s,i=0;
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
 Compare(arr1,arr2,s);
 
    return 0;
}

#include <stdio.h>
void Merge(int *arr1, int *arr2,int size)
{
    int i,j=0,arr3[2*size];
    for(i=0; i<size; i++)
    {
        arr3[j] = arr1[i];
        arr3[j+1] = arr2[i];
        j+=2;
    }
    for(i=0; i<size*2; i++)
    {
       printf("%d ",arr3[i]);
    }
    
}
int main()
{
 int s,i;
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
Merge(arr1,arr2,s);

   
    
    return 0;
}

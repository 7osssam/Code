#include <stdio.h>
void SwapArray(int *arr1, int *arr2, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        arr1[i] = arr1[i]^arr2[i];
        arr2[i] = arr1[i]^arr2[i];
        arr1[i] = arr1[i]^arr2[i];
    }
    printf("First array: ");
    for(i=0; i<size; i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\nSecond array: ");
    for(i=0; i<size; i++)
    {
        printf("%d ",arr2[i]);
    }
}
int main()
{
   int s,i;
   printf("Please enter the size: ");
   scanf("%d",&s);
   int a1[s],a2[s];
   printf("Enter first array: ");
   for(i=0; i<s; i++)
   {
       scanf("%d",&a1[i]);
   }
   printf("Enter second number: ");
   for(i=0; i<s; i++)
   {
       scanf("%d",&a2[i]);
   }
   SwapArray(a1,a2,s);

    return 0;
}

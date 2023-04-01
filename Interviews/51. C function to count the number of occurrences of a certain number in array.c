#include <stdio.h>
void Count(int *arr, int size, int num)
{
    int i,count=0;
    for(i=0; i<size; i++)
    {
        if(arr[i] == num)
        {
            count++;
        }
    }
    printf("No of occurance = %d",count);
}
int main()
{
   int s,i,n;
   printf("Enter size of array: ");
   scanf("%d",&s);
   int arr[s];
   printf("Enter elements of array: ");
   for(i=0; i<s; i++)
   {
       scanf("%d",&arr[i]);
   }
   printf("Please enter the number: ");
   scanf("%d",&n);
   Count(arr, s,n);
    return 0;
}

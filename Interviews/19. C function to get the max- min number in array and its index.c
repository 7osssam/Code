#include <stdio.h>
void MaxMin(int *arr, int size)
{
    int max=0,min=arr[0],i,ind1,ind2;
    for(i=0; i<size;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            ind1 = i;
        }
        else if(arr[i]<min)
        {
            min = arr[i];
            ind2 = i;
        }
    }
  printf("Max = %d\nMin = %d\nind1 = %d\nind2 = %d",max,min,ind1,ind2);
}
int main()
{
    int s,i;
    printf("Size of array: ");
    scanf("%d",&s);
    printf("Elments of array: ");
    int arr[s];
    for(i=0; i<s; i++)
    {
        scanf("%d",&arr[i]);
    }
    MaxMin(arr, s);
    return 0;
}

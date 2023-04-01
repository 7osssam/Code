#include <stdio.h>
void Max(int *arr,int size)
{
    int max = 0,i,count=0;
    for(i=0; i<size; i++)
    {
        if(arr[i]> max)
        {
            max = arr[i];
        }
    }
    for(i=0; i<size; i++)
    {
        if(arr[i] == max)
        {
            count++;
        }
    }
    printf("Maximum number = %d\nNumber of times = %d",max,count);
    
}
int main()
{
    int s,i;
    printf("Enter size of array: ");
    scanf("%d",&s);
    printf("Enter elements of array: ");
    int arr[s];
    for(i=0; i<s; i++)
    {
        scanf("%d",&arr[i]);
    }
Max(arr,s);
    return 0;
}

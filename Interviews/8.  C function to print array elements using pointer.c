#include <stdio.h>
#define SIZE 5
void PrintArray(int *arr)
{
    int *ptr=arr,i=0;
    while(arr[i] !='\0')
    {
       *ptr = arr[i];
        printf("%d ",*ptr);
        i++;
    }
}
int main()
{
    int a[SIZE],i;
    printf("Please enter elements of array: ");
    for(i=0; i<SIZE; i++)
    {
        scanf("%d",&a[i]);
    }
    PrintArray(a);
    return 0;
}

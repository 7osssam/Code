#include <stdio.h>
void Series(int size)
{
    int arr[size],i;
    arr[0] = 1;
    arr[1] = 2;
    for(i=2; i<size; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
   int s;
   printf("Enter size: ");
   scanf("%d",&s);
Series(s);
    return 0;
}

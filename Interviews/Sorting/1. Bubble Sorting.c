#include <stdio.h>
void Binary_Search(int *arr, int size)
{
    int temp;
    int i=0,j=0,flag=0;
    for(j=0; j<size; j++)
    {
        flag=1;
        for(i=0; i<size-j-1; i++)
        {
            if(arr[i]< arr[i+1])
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
    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int s,i=0;
    printf("Please enter size of array: ");
    scanf("%d",&s);
    int a[s];
    for(i=0; i<s; i++)
    {
        scanf("%d",&a[i]);
    }
    Binary_Search(a,s);
   

    return 0;
}

#include <stdio.h>

int RepeatedNum(int *arr, int size)
{
    int i=0,j=0;
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arr[i] == arr[j])
            {
                printf("%d ",arr[i]);
            }
        }
    }
}
int main()
{
    int i=0,s;

    int arr[] ={7,1,2,1,7,5,5};
    s = sizeof(arr)/sizeof(arr[0]);
    RepeatedNum(arr,s);
   
    return 0;
}

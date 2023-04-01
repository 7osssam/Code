#include <stdio.h>

int main()
{
    int arr[] = {7,2,8,3,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i=0, j=0;
    for(j=0; j<n; j++)
    {
          if(arr[j] != -1)
          {
            for(i=j+1; i<n-1; i++)
            {
                if(arr[j] == arr[i])
                {
                    arr[i] = -1;
                }
            }
          }
        
    }
    for(i=0; i<n; i++)
    {
        if(arr[i] != -1)
        {
            printf("%d ",arr[i]);
        }
    }
    return 0;
}

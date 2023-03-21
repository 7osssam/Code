#include <stdio.h>

int howmuch(int *p, int count)
{
    int i, flag=0;
    for(i = count; i > 0  ; i--)
    {
    if(p[i] == 0)
        flag++;
    }
    return flag;
}    

int main()
{
    int arr[11] = {0},i,n, zeros;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for(i = 0; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }
    printf("the elements are\n");
    for(i = 0; i < n; i++)
    {
      printf("%d\t", arr[i]);
    }
     printf("\n");   

    zeros = howmuch(arr, n);
    printf("number of zeros are %d\n", zeros);
    return 0;
}
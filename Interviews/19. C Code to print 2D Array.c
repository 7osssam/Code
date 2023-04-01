#include <stdio.h>

int main()
{  int r,c,i=0,j=0;
    printf("Please enter number of row: ");
    scanf("%d",&r);
    printf("Please enter number of column: ");
    scanf("%d",&c);
    int arr[r][c];
    printf("Please enter elements of array: ");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
           scanf("%d",&arr[i][j]);
        }
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
           printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
   
    return 0;
}

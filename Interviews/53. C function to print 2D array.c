#include <stdio.h>
void Print(int arr[][4], int size)
{
   int i,j;
   for(i=0; i<size; i++)
   {
       for(j=0; j<size; j++)
       {
           printf("%d ",arr[i][j]);
       }
       printf("\n");
   }
}
int main()
{
    int i,j,s;
    printf("Size of array: ");
    scanf("%d",&s);
    int arr[s][s];
    for(i=0; i<s; i++)
    {
        for(j=0; j<s; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    Print(arr,s);
    return 0;
}

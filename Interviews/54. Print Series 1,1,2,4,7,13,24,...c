#include <stdio.h>
#define SIZE 10
void Series(int *arr)
{
   arr[0] = 1;
   arr[1] = 1;
   arr[2] = 2;
   int i;
   for(i=3; i<SIZE; i++)
   {
       arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
   }
   printf("Sequence = ");
   for(i=0; i<SIZE; i++)
   {
       printf("%d ",arr[i]);
   }
}
int main()
{
   int a[SIZE];

Series(a);
    return 0;
}

#include <stdio.h>
void Arrange(int *arr, int num)
{
   int i=0;
   for(i=0; i<9 ;i++)
   {
       if(arr[i] != 1)
       {
         printf("%d ",arr[i]);
       }
       
   }
    for(i=5; i<9 ;i++)
   {
       arr[i] = 1;
       printf("%d ",arr[i]);
   }

}

int main()
{
   int arr[9] = {1,2,5,7,1,1,3,1,7};
 Arrange(arr,1);
    return 0;
}

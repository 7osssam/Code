#include <stdio.h>
int IndexOdd(int *arr)
{
   int i=0;
   while(arr[i] !=-1)
   {
       if(arr[i]%2 == 0)
       {
       i++;
       }
       else
       {
          return i;
           break;
       }
       
   }
    
}
int main()
{
   int arr[] = {2,4,6,3,8,10};
   int index;
   index = IndexOdd(arr);
   printf("The index of odd number = %d",index);
    return 0;
}

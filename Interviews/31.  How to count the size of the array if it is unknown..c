#include <stdio.h>

int main()
{
   int arr[] = {2,4,6,3,8,10};
  int s = sizeof(arr)/sizeof(arr[0]);
  printf("The size of array = %d",s);
    return 0;
}

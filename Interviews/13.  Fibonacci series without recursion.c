#include <stdio.h>
#define SIZE 100
int main()
{
  int arr[SIZE],i;
  arr[0] = 1;
  arr[1] = 1;
  for(i=2; i<SIZE; i++)
  {
      arr[i] = arr[i-1] + arr[i-2];
  }
  for(i=0; i<SIZE; i++)
  {
      printf("%d ",arr[i]);
  }
    return 0;
}

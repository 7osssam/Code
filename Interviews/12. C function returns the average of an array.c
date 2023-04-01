#include <stdio.h>
void Average_array(int *arr, int size)
{
    int sum,i;
    for(i=0; i<size; i++)
    {
        sum+=arr[i];
    }
    printf("Average = %.2f",(float)sum/size);
}
int main ()
{
  int s, i = 0;
  printf ("Please enter size of array: ");
  scanf ("%d", &s);
  int arr[s];
  printf ("Please enter elements of array: ");
  for (i = 0; i < s; i++)
    {
    scanf ("%d", &arr[i]);
        
    }
Average_array(arr, s);
  return 0;
}

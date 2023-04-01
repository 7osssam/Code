#include <stdio.h>
void BubbleSorting (int *arr, int size)
{
  int i = 0, j = 0, flag = 0, temp;
  for (i = 0; i < size; i++)
    {
      flag = 1;
      for (j = i + 1; j < size; j++)
	{

	  if (arr[i] > arr[i + 1])
	    {
	      temp = arr[i];
	      arr[i] = arr[i + 1];
	      arr[i + 1] = temp;
	      flag = 0;
	    }
	}
	if (flag == 1)
    {
      break;
    }
    }
  
}

void MostRepeated (int *arr, int size)
{
  int i, count = 0, max = 0, num;
  for (i = 0; i < size; i++)
    {
      if (arr[i] == arr[i + 1])
	{
	  count++;
	  if (count > max)
	    {
	      max = count;
	      num = arr[i];
	    }
	}
    }
  printf ("Most repeated number: %d", num);
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
  BubbleSorting (arr, s);
MostRepeated(arr,s);
  return 0;
}

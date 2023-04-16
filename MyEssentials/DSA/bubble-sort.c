#include <stdio.h>

// This function swaps values of two variables using pointers without using a third variable
void swap(int *num1, int *num2)
{
  *num1 = *num1 + *num2; // add x and y and store in x
  *num2 = *num1 - *num2; // subtract y from x and store in y
  *num1 = *num1 - *num2; // subtract y from x and store in x
}

int main()
{
  int n = 10;
  int arr[10];
  // scan the array
  for (size_t i = 0; i < n; i++)
  {
    printf("Enter the %dst number", i + 1);
    scanf("%d", &arr[i]);
  }
  // print the array
  for (size_t i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  // bubble-sort
  for (size_t step = 0; step < n - 1; step++)
  {
    int isSorted = 1; // if the array is sorted we don't need to check it again
                      // here we added - sort because after every step the last element is sorted and we don't need to check it again
    for (size_t i = 0; i < n - 1 - step; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        swap(&arr[i], &arr[i + 1]);
        isSorted = 0;
      }
    }
    if (isSorted) // if the array is sorted we don't need to check it again
    {
      break;
    }
  }

  printf("\nthe sorted array is\n");

  // print the array again
  for (size_t i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}

/******************************************************************************
(22) Write a c function that removes the repeated number of an input sorted array and
return a new array without the repeated numbers.
The function shall return error if the size of the input array is ZERO
The function takes four inputs:
a.Old array.
b.Old array size.
c.New array (empty array).
d.The size of the new array after fill it in the function.

int removeDuplicates(int arr_old[], int n_old, int arr_new[], int *n_new)
Ex:
  arr1 = {1,2,3,3,3,4,4,5,5,5}
→ arr2 = {1,2,3,4,5}
*******************************************************************************/

#include <stdio.h>

int removeDuplicates(int *arr_old, int n_old, int *arr_new, int *n_new)
{
    int i;
    if (n_old == 0)
    {
        return 0;
    }
    else
    {
        for (i = 0; i < n_old; i++)
        {
            if (arr_old[i] == arr_old[i + 1])
            {
                continue;
            }
            else
            {
                arr_new[*n_new] = arr_old[i];
                (*n_new)++;
            }
        }
    }
    return 1;
}
int main()
{
    int Arr[] = {1, 2, 3, 3, 3, 4, 4, 5, 5, 5};

    int Arr_size = sizeof(Arr) / sizeof(Arr[0]);

    int OutputArr[50] = {0};

    int OutputArr_size = 0;

    int result;

    result = removeDuplicates(Arr, Arr_size, OutputArr, &OutputArr_size);

    if (result == 1)
    {
        for (int i = 0; i < OutputArr_size; i++)
        {
            printf("%d ", OutputArr[i]);
        }
    }
    else
    {
        printf("Error");
    }

    return 0;
}
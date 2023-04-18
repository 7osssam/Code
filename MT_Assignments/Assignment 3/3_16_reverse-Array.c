/******************************************************************************
(16)Write a C function that takes an array as input and reverse it.
Input : 1,2,3,4,5
Output: 5,4,3,2,1
*******************************************************************************/
#include <stdio.h>
#define arr_size 10

void reverseArray(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
int main()
{
    int arr[arr_size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    reverseArray(arr, arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
}
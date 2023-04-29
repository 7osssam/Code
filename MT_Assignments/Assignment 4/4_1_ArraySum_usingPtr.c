// (1) C Program to compute sum of the array elements using pointers.

#include <stdio.h>
#define arr_size 5

int ArrSumPtr(int *ptr) // ptr is a pointer to the first element of the array
{
    int sum = 0;
    for (int i = 0; i < arr_size; i++)
    {
        sum = sum + *ptr;
        ptr++; // point to the next element
    }
    return sum;
}

int main()
{
    int arr[arr_size] = {1, 2, 3, 4, 5};
    int *Ptr = arr;

    printf("sum of arr (using Ptr): %d", ArrSumPtr(Ptr));
}
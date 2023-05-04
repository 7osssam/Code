// (4) C function to get the value of the smallest element in array using pointers.

#include <stdio.h>
#define arr_size 10

int MinimumNum(int *ptr, int size)
{
    int i;
    int mini = ptr[0]; // initialize mini with the first element of the array

    for (i = 0; i < size; i++)
    {
        if (ptr[i] < mini) // if the value of the element is less than mini
        {
            mini = ptr[i];
        }

        // ptr++; // point to the next element
    }

    return mini;
}

int main()
{
    int arr[arr_size];
    int *ptr = arr;

    int i;
    for (i = 0; i < arr_size; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("The minimum number is %d", MinimumNum(ptr, arr_size));
}
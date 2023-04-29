// (4) C function to get the value of the smallest element in array using pointers.

#include <stdio.h>
#define arr_size 10

int main()
{
    int arr[arr_size];
    int *ptr = arr;
    int mini = arr[0]; // initialize mini with the first element of the array

    int i;
    for (i = 0; i < arr_size; i++)
    {
        scanf("%d", &ptr[i]);
    }

    for (i = 0; i < arr_size; i++)
    {
        if (ptr[i] < mini) // if the value of the element is less than mini
        {
            mini = ptr[i];
        }

        // ptr++; // point to the next element
    }

    printf("mini: %d ", mini);
}
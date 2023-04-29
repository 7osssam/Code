// (5) C function to copy all elements of an array into another array using pointers.
// The two arrays have the same length and types.

#include <stdio.h>
#define arr_size 5
int main()
{
    int arr1[arr_size] = {2, 4, 6, 62, 45};
    int arr2[arr_size];

    int *ptr1 = arr1;
    int *ptr2 = arr2;

    for (int i = 0; i < arr_size; i++)
    {
        *ptr2 = *ptr1; // copy the value of the element

        ptr1++; // point to the next element
        ptr2++; // point to the next element
    }

    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr2[i]);
    }
}
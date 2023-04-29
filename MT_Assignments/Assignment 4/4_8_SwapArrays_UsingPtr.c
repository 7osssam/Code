// (8) Write a C function to swap the contents of two arrays with the same length using pointers.

#include <stdio.h>
#define arr_size 5

void swapArrayPtr(int *ptr1, int *ptr2)
{
    int temp;
    for (int i = 0; i < arr_size; i++)
    {
        temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;

        ptr1++; // point to the next element
        ptr2++; // point to the next element
    }
}

int main()
{
    int arr1[arr_size] = {1, 2, 4, 5, 7};
    int arr2[arr_size] = {11, 22, 33, 44, 55};

    int *ptr1 = arr1;
    int *ptr2 = arr2;

    printf("Before:\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr2[i]);
    }

    swapArrayPtr(ptr1, ptr2);
    printf("\nAfter:\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr2[i]);
    }
}
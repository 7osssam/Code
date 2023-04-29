// (3)C Program to read 10 integers into an array from user and print them in reversing order using pointers.

#include <stdio.h>
#define arr_size 10

int main()
{
    int arr[arr_size];
    int *ptr = arr;
    int i;

    for (i = 0; i < arr_size; i++)
    {
        scanf("%d", &ptr[i]);
    }

    ptr = ptr + arr_size - 1; // point to the last element of the array
    printf("Array in reverse order: ");

    for (i = 0; i < arr_size; i++)
    {
        printf("%d ", *ptr); // print the value of the element
        ptr--;               // point to the previous element
    }
}
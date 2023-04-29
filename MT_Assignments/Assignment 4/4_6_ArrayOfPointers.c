// (6) C Program to print all the array elements and the maximum number in array using array of pointers

#include <stdio.h>
#define arr_size 10

int main()
{
    int arr[arr_size] = {8, 3, 5, 26, 2, 1, 52, 1, 52, 13};
    int *arrPtr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        arrPtr[i] = &arr[i]; // assign the address of the element to the pointer array element
    }

    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", *arrPtr[i]); // print the value of the element
    }

    int max = *arrPtr[0]; // initialize max with the first element of the array

    for (int i = 0; i < arr_size; i++)
    {
        if (max < *arrPtr[i])
        {
            max = *arrPtr[i];
        }
    }

    printf("\nMax num: %d ", max);
}
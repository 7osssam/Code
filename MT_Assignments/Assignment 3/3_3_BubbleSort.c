/******************************************************************************
(3) Writea C function that use the  algorithm to sort an integer array in ascending order
(search for the bubble sorting algorithm).
*******************************************************************************/
#include <stdio.h>

// This function swaps values of two variables using pointers without using a third variable
void swap(int *num1, int *num2)
{
    *num1 = *num1 + *num2; // add x and y and store in x
    *num2 = *num1 - *num2; // subtract y from x and store in y
    *num1 = *num1 - *num2; // subtract y from x and store in x
}

void BubbleSort(int *arr, int arr_size)
{
    for (int step = 0; step < arr_size - 1; step++) // loop for steps //
    {
        int isSorted = 1; // sorted by default

        // we added (....- step) because after every step the last element is sorted and we don't need to check it again
        for (int i = 0; i < arr_size - 1 - step; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]); // swap if the element is greater than the next element

                isSorted = 0; // not sorted
            }
        }

        if (isSorted == 1) // if we didn't swap any element then the array is sorted
            break;
    }
}

int main()
{

    int arr[10] = {9, 8, 7, 1, 3, 2, 4, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // printf("Enter %d elements in the array to sort\n", arr_size);
    // for (int i = 0; i < arr_size; i++) // get the array
    // {
    //     scanf("%d", &arr[i]);
    // }

    printf("The Before Array\n");
    for (int i = 0; i < arr_size; i++) // print the array
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    BubbleSort(arr, arr_size);

    printf("The After Array (Sorted)\n");
    for (int i = 0; i < arr_size; i++) // print the sorted array
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

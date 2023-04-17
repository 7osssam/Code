/******************************************************************************
(4) Write a C function that use the selection sort algorithm to sort an integer array in ascending order
(search for the selection sorting algorithm).
*******************************************************************************/

#include <stdio.h>

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void SelectionSort(int *arr, int arr_size)
{
    int min;
    int indexOfMin;
    for (int steps = 0; steps < arr_size - 1; steps++)
    {
        indexOfMin = steps;
        for (int j = steps + 1; j < arr_size; j++)
        {
            if (arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        swap(&arr[indexOfMin], &arr[steps]);
    }
}
int main()
{ // 1 2 3 4 5 6 7 7 8 9

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

    SelectionSort(arr, arr_size);

    printf("The After Array (Sorted)\n");
    for (int i = 0; i < arr_size; i++) // print the sorted array
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

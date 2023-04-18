/******************************************************************************
(5)Write a C function to return the index of LAST occurrence of a number in a given array.
Array index start from 0. If the item is not in the list return -1.  (Linear Search Algorithm)
Example: Array = {1,2,3,4,4,4} ----> The required number is 4 it should return 5
*******************************************************************************/

#include <stdio.h>

// time complexity: O(n)
int LinearSearch(int arr[], int target, int arr_size)
{
    for (int i = arr_size; i > 0; i--) // reverse loop
    {
        if (arr[i] == target) // if the element is found
        {
            return i;
        }
    }
    return -1; // if the element is not found
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 4}; // unsorted array (linear search)

    int target;                                  // the element to be searched
    int arr_size = sizeof(arr) / sizeof(arr[0]); // to get the size of the array

    printf("Enter a num :");
    scanf("%d", &target);

    int result = LinearSearch(arr, target, arr_size); // linear search

    if (result == -1)
        printf("\nNOT FOUND");
    else
        printf("\n%dst [index %d] of the array", result + 1, result);

    return 0;
}
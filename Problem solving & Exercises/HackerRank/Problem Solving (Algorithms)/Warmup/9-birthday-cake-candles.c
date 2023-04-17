// ? https://www.hackerrank.com/challenges/birthday-cake-candles/problem
// print the number of times the maximum number is repeated in the array
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr_size;
    scanf("%d", &arr_size);

    // dynamic array allocation for
    signed int *arr = (signed int *)malloc(arr_size * sizeof(int));

    // scan array elements
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = arr[0], maxCounter = 0;
    // loop through the array to find the max number
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > max) // if the current element is greater than the max
        {
            max = arr[i];   // update the max
            maxCounter = 0; // reset the counter when a new max is found
        }
        if (max == arr[i])
        {
            maxCounter++; // increment the counter when the current element is equal to the max
        }
    }
    printf("%d", maxCounter);

    return 0;
}
//? https://www.hackerrank.com/challenges/mini-max-sum/problem

#include <stdio.h>
#include <stdlib.h>
#define arr_size 5

int main()
{
    // dynamic array allocation for
    int *arr = (int *)malloc(arr_size * sizeof(int));

    // scan array elements
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // minimum sum = sum of all elements - maximum number
    // maximum sum = sum of all elements - minimum number
    long sum = 0;                    // sum of all elements //!long to avoid overflow
    int mini = arr[0], max = arr[0]; // minimum and maximum numbers in the array

    for (int i = 0; i < arr_size; i++)
    {
        sum = sum + arr[i];
        if (arr[i] < mini) // if the current element is smaller than the minimum
        {
            mini = arr[i]; // update the minimum
        }
        if (arr[i] > max) // if the current element is bigger than the maximum
        {
            max = arr[i]; // update the maximum
        }
    }
    printf("%ld %ld", (sum - max), (sum - mini)); // print the minimum and maximum sums

    free(arr); // free the allocated memory
}

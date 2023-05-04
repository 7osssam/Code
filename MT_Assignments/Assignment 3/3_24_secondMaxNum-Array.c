/******************************************************************************
(24) Write a C function to find the second largest number in an array and return its value.
*******************************************************************************/
#include <stdio.h>

int secondMax(int *arr)
{
    int max = arr[0];
    int secMax = arr[0];

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max) // identify max value in array
        {
            secMax = max; // assign max value to secound max value
            max = arr[i]; // assign new max value
        }
        // if number is greater than secound max and less than max
        else if (arr[i] > secMax && arr[i] < max) // identify secound max value in array
        {
            secMax = arr[i]; // assign new secound max value
        }
    }

    return secMax;
}

int main()
{
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Second Max: %d\n", secondMax(arr));
}
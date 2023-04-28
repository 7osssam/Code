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
        if (arr[i] > max)
        {
            secMax = max;
            max = arr[i];
        }
        else if (arr[i] > secMax && arr[i] < max)
        {
            secMax = arr[i];
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
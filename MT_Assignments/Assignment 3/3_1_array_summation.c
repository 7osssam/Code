/******************************************************************************
(1)The sum of an array is the sum of its individual elements. For example,
if an array is numbers = {1, 2, 3, 4}, the sum of the array is 1+2+3+4 = 10.
Function Description:
Complete the function summation.
The function must return the integer sum of the numbers array.
int summation(int numbers_size, int* numbers)
*******************************************************************************/

#include <stdio.h>
#define arr_size 5 // array size

long summation(int numbers_size, int *numbers)
{
    long sum; // long is used because the sum of the array may be greater than the int range
    for (int i = 0; i < numbers_size; i++)
    {
        sum = sum + numbers[i];
    }
    return sum;
}

int main()
{
    int arr[arr_size];
    long result;

    puts("Enter 5 numbers:");
    for (int i = 0; i < arr_size; i++) // input array
    {
        scanf("%d", &arr[i]);
    }

    result = summation(arr_size, arr);

    puts("summation:");
    printf("%ld", result);

    return 0;
}
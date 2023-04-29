// (12) Array that contains integer values, some of these values are repeated with an even number of repetitions,
// and only one value is repeated with an odd number of repetitions.
// Write a C function that take the array as input and the array size and
// return the number which has odd numbers of repetitions.

#include <stdio.h>
#define arr_size 10

int OddRepeated(int *arr)
{
    int freq[10] = {0}; // initialize all elements with 0
    int Oddrep;

    for (int i = 0; i < arr_size; i++)
    {
        freq[arr[i]]++; // increment the value of the element in the freq array
    }

    for (int i = 0; i < 10; i++)
    {
        if (freq[i] % 2 != 0 && freq[i] != 0) // if the value of the element is odd and not equal to 0
        {
            return i;
        }
    }
    return -1; // error
}

int main()
{
    int arr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Odd repeated num: %d ", OddRepeated(arr));
}
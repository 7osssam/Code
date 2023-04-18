/******************************************************************************
(18)Write a C function that return the count of the longest consecutive occurrence of a given number in an array.
Ex: Array={1,2,2,3,3,3,3,4,4,4,4,3,3,3} and searching for 3
➔ result = 4
*******************************************************************************/
#include <stdio.h>

int MaxConsecutiveNum(int *arr, int n, int num)
{
    int counter = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            counter++;

            if (counter > max)
                max = counter;
        }
        else
        {
            counter = 0;
        }
    }
    return max;
}
int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    puts("Enter a number: ");
    int num;
    scanf("%d", &num);
    puts("The longest consecutive occurrence of the given number is: ");
    printf("%d ", MaxConsecutiveNum(arr, n, num));
}
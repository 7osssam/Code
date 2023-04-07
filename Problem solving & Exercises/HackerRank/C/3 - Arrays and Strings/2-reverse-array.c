// ? https://www.hackerrank.com/challenges/reverse-array-c/problem
#include <stdio.h>
#include <stdlib.h>

void Swap_Advanced(int *num1, int *num2) // swap using pointers (pass by reference)
{
    *num1 = *num1 + *num2; // add x and y and store in x
    *num2 = *num1 - *num2; // subtract y from x and store in y // x = x + y - y = x
    *num1 = *num1 - *num2; // subtract y from x and store in x // y = x + y - x = y
}
int main()
{
    int num, *arr, i;
    scanf("%d", &num);

    arr = (int *)malloc(num * sizeof(int)); // memory allocation for the array

    for (i = 0; i < num; i++) // loop for taking input of the array
    {
        // scanf( "%d" , arr+i); //using pointer notation
        scanf("%d", &arr[i]); // using array notation
    }

    //! * Write the logic to reverse the array. */
    int temp = 0;
    for (i = 0; i < num / 2; i++)
    {
        Swap_Advanced(&arr[i], &arr[num - i - 1]);
    }

    for (i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
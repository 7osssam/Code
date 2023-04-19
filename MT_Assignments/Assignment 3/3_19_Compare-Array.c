/******************************************************************************
(19) Write a C function that compare between 2 arrays with the same length.
It shall return 0 if the two arrays are identical and 1 if not.
*******************************************************************************/

#include <stdio.h>

int ArrayCompare(int *a, int a_size, int *b, int b_size) // return 0 if the two arrays are identical and 1 if not.
{
    if (a_size != b_size)
    {
        return 1; // not the same
    }

    for (int i = 0; i < a_size; i++) // a_size == b_size
    {
        if (a[i] != b[i])
        {
            return 1; // not the same
        }
    }
    return 0;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};

    int a_size = sizeof(a) / sizeof(a[0]);
    int b_size = sizeof(b) / sizeof(b[0]);

    if (ArrayCompare(a, a_size, b, b_size))
    {
        puts("NOT THE SAME");
    }
    else
    {
        puts("THE SAME");
    }

    return 0;
}
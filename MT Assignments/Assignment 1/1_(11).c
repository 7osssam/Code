// (11) Print sum of first 100 integers. (With data validation)

#include <stdio.h>

int main()
{
    int N = 100;
    int sum;
    sum = (N * (N + 1)) / 2;

    printf("Sum 0 -> 100 is :%d", sum);

    return 0;
}
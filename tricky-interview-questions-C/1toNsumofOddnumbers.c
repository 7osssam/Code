#include <stdio.h>
#include <math.h>

int main()
{

    int n = 9, i = 0;
    double sum = 0;
    for (i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            printf("i is %d\n", i);
            sum += (i);
        }
    }
    printf("sum of (1+3+5...+n) numbers is %f\n", sum);
    return 0;
}
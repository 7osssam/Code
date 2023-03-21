#include <stdio.h>


int main()
{
    int n = 1661, sum=0, rem =0;
    while(n != 0)
    {
        sum = sum+ n%10;
        n = n/10;
    }
    printf("sum of digits is %d\n", sum);
    return 0;
}
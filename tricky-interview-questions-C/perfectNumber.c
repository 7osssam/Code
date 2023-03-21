#include <stdio.h>

int main()
{
    int n = 6, i, factor, sum=0;
    for(i =1; i < n ; i++)
    {
        if(n % i ==0)
        {
            sum = sum + i;
        }
    }
    if(n == sum)
    printf("%d is perfect number\n", n);
    else
    printf("%d is not perfect number\n", n);
    return 0;
}
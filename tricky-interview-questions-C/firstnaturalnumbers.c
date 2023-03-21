#include <stdio.h>



int main()
{
    
    int n = 10, i = 0, sum= 0;
    for(i = 0; i <= n;i++)
    {
        sum += i;
    }
    printf("sum of first 10 natural numbers is %d", sum); 
    return 0;
}
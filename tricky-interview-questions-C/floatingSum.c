#include <stdio.h>



int main()
{
    
    int n = 4 , i = 0;
    float sum= 0;
    for(i = 1 ; i <= n;i++)
    {
        sum += (1/i);
	printf("sum is %f", sum);
    }
    printf("sum of first 10 natural numbers is %f", sum); 
    return 0;
}
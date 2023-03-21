
#include <stdio.h>
int main()
{
    int n = 6, i=2, factor, sum=1;
    for(i =n; i >0 ; --i)
    {
        sum = sum * i;
    }
    printf("factorial is %d\n", sum);
    return 0;
}

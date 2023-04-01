#include <stdio.h>
int MaxCall(int num)
{
    static int max;
    if(num>max)
    {
        max = num;
    }
    return max;
}
int main()
{
    int n;
    n = MaxCall(2);
    n = MaxCall(5);
    n = MaxCall(3);
   printf("Maximum number = %d",n);
    return 0;
}

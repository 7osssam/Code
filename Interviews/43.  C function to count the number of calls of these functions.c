#include <stdio.h>
int Calls(void)
{
    static int count=0;
    count++;
    return count;
}
int main()
{
    int x;
    x =  Calls();
    x =  Calls();
    x =  Calls();
    printf("%d",x);
    return 0;
}

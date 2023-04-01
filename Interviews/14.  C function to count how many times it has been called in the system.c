#include <stdio.h>
int NoOfCalls(void)
{
    static int count;
    count++;
    return count;
}
int main()
{
    int x;
 NoOfCalls();
 NoOfCalls();
x = NoOfCalls();
printf("No. of Calls = %d",x);
    return 0;
}

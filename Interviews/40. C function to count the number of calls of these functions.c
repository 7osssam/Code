#include <stdio.h>
void CountFunctionCalls(void)
{
    static int count =0;
    count++;
    printf("The function call = %d\n",count);
}
int main()
{

 CountFunctionCalls();
 CountFunctionCalls();
 CountFunctionCalls();

    return 0;
}

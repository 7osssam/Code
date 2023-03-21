#include <stdio.h>

int main()
{
    int n = 1;
    BEGIN:
    n = n+1;
    if(n >0)
    goto BEGIN;
    return 0;
}

//output is nothing, since nothing is being printed
// it can run into infinite loop
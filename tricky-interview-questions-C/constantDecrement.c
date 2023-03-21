#include <stdio.h>

int main()
{
    int c = --2;
    printf("c  is %d\n", c);    
    return 0;
}


// error because we cannot decrement a constant 
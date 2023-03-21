#include <stdio.h>

int main()
{
    int a, b, c;
    a = 15;
    b = 10;
    c = a &b;
    printf("c is %d\n", c);
    return 0;
}

//Output is 10. It performs a bitwise AND operation
//between 10 and 15, and finally, the value is converted into 
//decimal value.
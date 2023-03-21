#include <stdio.h>

int main()
{
    int i = 10;
    i = !i > 14;
    printf("i value is %d\n", i);

    return 0;
}

//output is 0, i gets substituted to its 
//respective place
//!T > 14
//F > 14
// 0 > 14
//F  false value is deduced as 0 in C language.
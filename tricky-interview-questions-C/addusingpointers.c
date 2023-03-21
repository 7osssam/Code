#include <stdio.h>

int main()
{
    int a = 5, b = 4;
    int *c = &a, *d= &b;
    printf("%d\n",*c + *d);
    return 0;
}

//the contents of the  integer a and b are
//accessed using the pointers c and d.

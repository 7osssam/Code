#include <stdio.h>

int main()
{
    float p = 3.2, q = 6.0;
    int r = 25;
    if(r)
    {
     p = p +2.3;
     q = p+ q;
    }
    printf(" p is %f, q is %f\n", p,q);
    return 0;
}

//output is 5.500000, q is 11.500000
//a positive value is treated as True
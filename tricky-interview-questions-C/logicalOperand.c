#include <stdio.h>

int main()
{
    int x,y,z;
    x = 0;
    y = 1;
    z = x && ++y;
    printf("x: %d\n",x);
    printf("y: %d\n",y);
    printf("z: %d\n",z);
    return 0;
}

//z is 0, because False AND True is always zero.
//since the first operand is 0, the second operand will not
//execute. So x is 0, y = 1 and z =0. 
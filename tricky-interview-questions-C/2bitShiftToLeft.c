#include <stdio.h>

int main()
{
    int i = 10;
    i = i << 2;
    printf("i value is %d\n", i);

    return 0;
}

//output is 40, 
//10 i binary is 0000 1010
//after it is hifted to 2 bits 
// it becomes 0010 1000
// it is multiplied with 2 power
// for each bit and th efinal answer is 40 in decimal
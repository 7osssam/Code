#include <stdio.h>

struct point{
    int x;
    int y;
};

int main()
{
   
    struct point po; 
    printf("struct size is %d\n", sizeof(struct point));
    printf("struct size is %d\n", sizeof(po));
    return 0;
}

//to determine the structure size, we use sizeof 
//and it is done in either way
// sizeof(strcut point) or sizeof(po)
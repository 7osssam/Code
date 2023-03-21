#include <stdio.h>

struct point{
    int x;
    int y;
};



int main()
{
   
    struct point po; 
    po.x =2;
    po.y = 3;
    printf("x is %d\n", po.x);
    printf("y is %d\n", po.y);

    return 0;
}

//to access the structure elements, we use dot operator
//and it has the highest operator in C.
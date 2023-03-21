#include <stdio.h>

int main()
{
    int a[5] = {10,20,30,40,50};
    printf("%d\n", a[2]);
    printf("%d\n", 2[a]);
    printf("%d\n", a[-1]);
    return 0;
}

//output is 30, 30 and 0
//a[2] = *(a+2) = 30
//2[a] = *(2+a) = 30
//a[-1] = *(a-1) = garbage value
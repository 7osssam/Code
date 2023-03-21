#include <stdio.h>

int main()
{
    int x = 1, y =0, a;
    a = !!x + !y;
    printf("%d\n", a);
        return 0;
}

// answer is 2, NOT of True is False, and not of False is True
//  !!(T) + !(F)
//  !F  + T
//  T + T
// any non zero value is treated as 1
// so, the answer is 2.
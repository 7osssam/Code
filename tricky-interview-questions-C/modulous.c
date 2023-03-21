#include <stdio.h>

int main()
{
    printf("%d, %d, %d, %d, %d\n", 5%2, -5%2, 5%-2, -5 %-2, 2%5);
        return 0;
}

//the sign of the remainder will always be equal to the sign of the numerator.
//for 2 % 5, the answer is zero.
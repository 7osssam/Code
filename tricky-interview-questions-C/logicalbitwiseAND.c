#include <stdio.h>

int main()
{
    printf("logical :%d, bitwise: %d\n", 15 && 5, 15 & 5);
        return 0;
}

// && logical AND, it is treated T && T, answer is 15
// & bitwaise AND, it is operated bit by bit, answer is 5

/***************************************************
(3) Given an integer number we want to know the value of the 4𝑡ℎ least significant
bit in num’s binary representation, For example if num = 23 we first convert it to
its binary representation (10111). When we count the bits from least to most
significant, we see that the 4𝑡ℎleast significant bit is 0.
****************************************************/
#include <stdio.h>

#define GIT_BIT(num, bit) ((num >> (bit - 1)) & 1)

int main()
{
    // int num = 23;
    int num = 0b00010111;

    printf("%d", GIT_BIT(num, 4));
}
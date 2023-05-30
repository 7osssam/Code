/***************************************************
(1) Write a C Macro GET_BIT to read certain bit in a register or variable.
The Macro inputs are the register or variable and the bit number.
****************************************************/

#include <stdio.h>

#define GIT_BIT(reg, bit) ((reg >> bit) & 1)

int main()
{
    int reg = 0b00010010;
    int bit = 4;
    printf("%d\n", GIT_BIT(reg, bit));
    return 0;
}
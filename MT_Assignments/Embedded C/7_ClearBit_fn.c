/***************************************************
(7) Write a C function that clears a specified bit in a giver number (bit number
starts from 0), and return the new value of the number. If not possible return the
same number as it is.
Example:
    Input Number = 3
    Bit Position = 0
    Result = 2
****************************************************/

#include <stdio.h>
// #define CLEAR_BIT(num, bit) ((num) & ~(1 << (bit)))

unsigned int ClearBit(unsigned int input, unsigned int bit)
{
    input = input & ~(1 << bit);
    return input;
}

int main()
{
    int num;

    printf("%d", ClearBit(3, 0)); // expected output: 2
    int d;
}
// 16 - Write a C function to count the number of 1’s in an unsigned //! 8-bit integer.

#include <stdio.h>
#define CHAR_SIZE sizeof(char) * 8
#define TestBit(x, y) (x & (1 << y))

int countOnes32(unsigned int num)
{
    // unsigned 8-bit integer
    unsigned char mask = 0x80; // binary: 1000 0000
    int count = 0;

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        if ((num & mask) != 0) // true if num & mask = non-zero
        {
            count++;
        }

        mask = mask >> 1;
    }

    // another approach
    // while (num) // while num is not zero
    // {
    //     // if (num & 1) -> true then count = count + 1 else count = count + 0
    //     count = count + (num & 1);
    //     num = num >> 1;
    // }

    return count;
}

int main()
{
    // 0 -> 255
    unsigned char num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Num %d has %d one bit", num, countOnes32(num));
    return 0;
}
// 185   = 1011 1001 // 5 ones
// 250   = 1111 1010 // 6 ones
//  mask = 1000 0000
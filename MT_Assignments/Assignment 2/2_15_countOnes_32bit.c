// 15 - Write a C function to count the number of 1’s in an unsigned //! 32-bit integer.

#include <stdio.h>
#define INT_SIZE sizeof(int) * 8
#define TestBit(x, y) (x & (1 << y))

int countOnes32(unsigned int num)
{
    // unsigned 32-bit integer
    unsigned int mask = 0x80000000; // binary: 1000 0000 0000 0000 0000 0000 0000 0000
    int count = 0;

    for (int i = 0; i < INT_SIZE; i++)
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
    // 0 -> 65,535
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Num %d has %d one bit", num, countOnes32(num));
    return 0;
}

// 15   = 0000 0000 0000 0000 0000 0000 0000 1111 // 4 ones
// 2286 = 0000 0000 0000 0000 0000 1000 1110 1110 // 7 ones
// mask = 1000 0000 0000 0000 0000 0000 0000 0000

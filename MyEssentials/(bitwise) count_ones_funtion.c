
#include <stdio.h>
#define INT_SIZE sizeof(unsigned int) * 8

// function to count the maximum number of consecutive 1's in an unsigned 32 bits integer
int maxOnes(int num)
{
    int max = 0;
    int count = 0;
    unsigned int mask = 0x80000000;     // 32 bits mask
    for (int i = 1; i <= INT_SIZE; i++) // loop through all bits
    {
        if (num & mask) // the result is a any value other than 0 (1 bit) //!any value --> true
        {
            count++;
            if (count > max)
            {
                max = count;
            }
        }
        else // if bit is exactly 0
        {
            count = 0; // reset count
        }
        mask = mask >> 1; // shift mask to the right
    }
    return max;
}

// function to count the maximum number of consecutive 0's in an unsigned 32 bits integer
int maxZeros(int num)
{
    // this function doesn't work if with numbers that take less than 32 bits because it will count the leading 0's
    // so we only need to loop through all its bits
    int max = 0;
    int count = 0;
    unsigned int mask = 0x80000000;     // 32 bits mask
    for (int i = 1; i <= INT_SIZE; i++) // loop through all bits
    {
        if (num & mask) // the result is a any value other than 0 (1 bit) //!any value --> true
        {
            count = 0; // reset count
        }
        else if ((num & mask) == 0) // if bit is exactly 0
        {
            count++;
            if (count > max)
            {
                max = count;
            }
        }
        mask = mask >> 1; // shift mask to the right
    }
    return max;
}

// function to count the maximum number of consecutive 0's //!between 1’s in an unsigned 32 bits integer
int maxZerosbetween(int num)
{
    int max = 0;
    int count = 0;
    unsigned int mask = 0x80000000; // 32 bits mask
    for (int i = 1; i <= INT_SIZE; i++)
    {
        if (num & mask) // the result is a any value other than 0 (1 bit) //!any value --> true
        {
            // we only set max once we have a 0 bit after a 1 bit
            if (count > max)
            {
                max = count;
            }
            count = 0; // then we reset count
        }
        else if ((num & mask) == 0) // if bit is exactly 0
        {
            count++;
        }

        mask = mask >> 1;
    }
    return max;
}

int main()
{
    // 32 bits unsigned integer
    unsigned int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Max consecutive 1's %d\n", maxOnes(num));
    printf("Max consecutive 0's %d\n", maxZeros(num));
    printf("Max consecutive 0's between 1's %d\n", maxZerosbetween(num));

    return 0;

    //  system("pause");
    //
}

// test case
// unsigned int num = 0b10110101000111000011111100100000;
// Max consecutive 1's 6
// Max consecutive 0's 5
// Max consecutive 0's between 1's 4
// 20 - Write a C function to count the maximum number of consecutive 1’s in an unsigned 16 bits integer

#include <stdio.h>
#define SHORT_SIZE sizeof(unsigned short) * 8

int maxOnes(int num)
{
    int max = 0;
    int count = 0;
    unsigned short mask = 0x8000; // 16 bits mask
    for (int i = 1; i <= SHORT_SIZE; i++)
    {
        if ((num & mask) != 0) // if bit is 1
        {
            count++;
            if (count > max)
            {
                max = count;
            }
        }
        else
        {
            count = 0;
        }
        mask = mask >> 1;
    }
    return max;
}

int main()
{
    unsigned short num;

    // printf("Enter a number: ");
    scanf("%d", &num);

    printf("%d", maxOnes(num));

    return 0;
}
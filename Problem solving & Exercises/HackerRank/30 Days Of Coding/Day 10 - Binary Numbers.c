#include <stdio.h>
#define int_size sizeof(int) * 8

int maxOnes(int num)
{
    int max = 0;
    int count = 0;
    unsigned int mask = 1;
    for (int i = 1; i <= int_size; i++)
    {
        if ((num & mask) != 0)
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
        mask = mask << 1;
    }
    return max;
}

int main()
{
    unsigned int num;

    scanf("%d", &num);

    printf("%d", maxOnes(num));
    return 0;
}
// unsigned int num = 0b10110101000111000011111100100000;
// Max consecutive 1's 6
// Max consecutive 0's 5
// Max consecutive 0's between 1's 4
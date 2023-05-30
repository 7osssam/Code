/*****************************************************
(8) Write a C function to reverse the binary of an 8-bits number. For
example if the input number is 10001101 the output number should be
10110001.
*****************************************************/
#include <stdio.h>

void PrintBinary(unsigned char num)
{
    unsigned char mask = 1 << (sizeof(num) * 8 - 1);
    while (mask)
    {
        if (num & mask)
            printf("1");
        else
            printf("0");
        mask >>= 1;
    }
    printf("\n");
}
unsigned char Reverse_8Bits(unsigned char num)
{
    unsigned int rev = 0;
    while (num)
    {
        rev <<= 1;
        if (num & 1) // if LSB is 1
        {
            rev |= 1; // set 1 in rev
        }
        num >>= 1;
    }
    return rev;
}
void test(int num)
{
    int count = 0;
    while (num)
    {
        count++;
        num >>= 1;
    }
    for (int i = 0; i < count; i++)
    {
    }
}

int main()
{

    unsigned char num = 0b10001101;

    PrintBinary(num);

    Reverse_8Bits(num);

    PrintBinary(Reverse_8Bits(num));
}
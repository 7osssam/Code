/***************************************************
(6) Write a C function to perform a right circular shift for an unsigned 32 bits
integer a given number of times and copy the output to third argument, and
return 0 if OK and 0xFF if the number of shifts > 32 in this case copy input to
output without doing any shifts.

unsigned char RightCircularShift(unsigned int InputNumber, int NumberOfShifts, unsigned int * pOutput)
****************************************************/

#include <stdio.h>
#define ROR(reg, num) (((REG >> (num)) | (REG << (32U - (num)))))

unsigned char RightCircularShift(unsigned int InputNumber, int NumberOfShifts, unsigned int *pOutput)
{
    if (NumberOfShifts > 32)
    {
        *pOutput = InputNumber;
        return 0xFF;
    }
    else
    {
        *pOutput = (InputNumber >> NumberOfShifts) | (InputNumber << ((sizeof(unsigned int) * 8) - (NumberOfShifts)));

        return 0;
    }
}

int main()
{
    unsigned int num = 0x12345678;
    unsigned int Output;
    RightCircularShift(num, 8, &Output);

    printf("Input Number: %x\nOutput Number: %x\n",
           num, Output);

    return 0;
}

// Input Number : 0x12345678
// Output Number: 0x78123456
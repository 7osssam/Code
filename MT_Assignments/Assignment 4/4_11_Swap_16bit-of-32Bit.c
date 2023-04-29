// (11) Writea c program that SWAP the value of the two 16-bits of 32-bits integer number

#include <stdio.h>

int main()
{
    int unit32Bit = 0x22224444; // 32 bit number

    short *FirstBitPtr = &unit32Bit;     // pointer to the first 16 bits of the 32 bit number
    short *SecondBitPtr = FirstBitPtr++; // pointer to the second 16 bits of the 32 bit number

    short temp; // temporary variable to hold the value of the first 16 bits

    printf("%x", unit32Bit); // before swap

    temp = *FirstBitPtr;          // temp holds the value of the first 16 bits
    *FirstBitPtr = *SecondBitPtr; // first 16 bits now hold the value of the second 16 bits
    *SecondBitPtr = temp;         // second 16 bits now hold the value of the first 16 bits

    printf("\n%x", unit32Bit); // after swap
}
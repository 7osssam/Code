/*
 ===================================================================================================
 Name        : Operators_Ex5.c
 Author      : Mohamed Tarek
 Description : Code to demonstrate the capability of the Bitwise operators
 ===================================================================================================
 */

#include <stdio.h>

int main(void)
{
    unsigned char var1 = 0x05, var2 = 0x0A;                          // 0000 0101 , 0000 1010 // 5 , 10
    printf("Result of Andind the two variables: %x\n", var1 & var2); // 0000 0000 // 0x00 // hex
    printf("Result of Oring the two variables: %x\n", var1 | var2);  // 0000 1111 // 0x0F // hex
    printf("Result of Xor the two variables: %x\n", var1 ^ var2);    // 0000 1111 // 0x0F // hex
    printf("Result of 1'complement for var1: %x\n", ~var1);          // 1111 1010 // 0xFA // hex
    printf("Result of 1'complement for var2: %x\n", ~var2);          // 1111 0101 // 0xF5 // hex
    return 0;
}

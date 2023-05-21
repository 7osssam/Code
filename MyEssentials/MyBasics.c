#include <stdio.h>
#define INT_SIZE sizeof(unsigned int) * 8

//! ========================== Swap (using pointers) ==========================  //
void swapAdvanced(int *num1, int *num2) // with no temp variable
{
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}
//?? using this method, there is a risk of overflow if the sum of the numbers is greater than the maximum value that can be stored by an integer.
//! ========================== Swap (temp) ===================================  //
void swap(int *num1, int *num2) // using temp variable
{
    int temp;
    temp = *num1;  // save the value of num1
    *num1 = *num2; // assign the value of num2 to num1
    *num2 = temp;  // assign the saved value of num1 to num2
}
//! ========================== Swap (temp) ===================================  //
void swapPointers(int **ptr1, int **ptr2) // using temp variable
{
    int *temp;
    temp = *ptr1;  // save the value of ptr1 (address of num1) to temp
    *ptr1 = *ptr2; // assign the value of ptr2 (address of num2) to ptr1
    *ptr2 = temp;  // assign the saved value of ptr1 (address of num1) to ptr2 (address of num2)
}

//! ========================== Power of two ==============================  //
int isPowerOfTwo(int n) // time complexity: O(log n)
{
    if (n <= 0) // 0 is not a power of 2
    {
        return 0;
    }
    while (n != 1) // while number is not 1
    {
        if (n % 2 != 0) // if number is not divisible by 2
        {
            return 0;
        }
        n /= 2; // divide number by 2
    }
    return 1;
}
//! ========================== isPowerOfTwo_Advanced ======================  //
int isPowerOfTwo_Advanced(int num) // time complexity: O(1)
{
    if (num <= 0) // 0 is not a power of 2 and negative numbers are not power of 2
        return 0;

    if ((num & (num - 1)) == 0) // if number is a power of 2, then it will have only 1 bit set
    {
        return 1; // number is a power of 2
    }
    else
    {
        return 0; // number is NOT a power of 2
    }
}
//! ========================== fibonacci of nth ============================  //
int fibOfN(int num)
{
    // Recursive approach
    // time complexity: O(2^n)

    if (num == 0) // base case
    {
        return 0;
    }
    else if (num == 1) // base case
    {
        return 1;
    }
    return fibOfN(num - 1) + fibOfN(num - 2);
}

//! ========================== fibonacci sequence ===========================  //
void printFibonacci(int num)
{
    // Iterative approach
    // time complexity: O(n)
    int first = 0, second = 1, next;

    for (int i = 0; i <= num; i++)
    {
        if (i <= 1)
        {
            next = i;
        }
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
    // printf("%d ", next); // to get the nth fibonacci number
}

//! ========================== Power of three ========================== //
int isPowerOfThree(int num) // time complexity: O(log n)
{
    if (num <= 0) // 0 is not a power of 3
    {
        return 0;
    }
    while (num != 1) // while number is not 1
    {
        if (num % 3 != 0) // if number is not divisible by 3
        {
            return 0;
        }
        num /= 3; // divide number by 3
    }
    return 1;
}

//?============================== Bit Manipulation =========================================================

//! ========================== countSetBits (ones) ========================================== //
// function to count the number of 1's in an unsigned 32 bits integer
int countOnes(int num)
{
    int count = 0;
    unsigned int mask = 0x80000000;     // 32 bits mask
    for (int i = 1; i <= INT_SIZE; i++) // loop through all bits
    {
        if (num & mask) // the result is a any value other than 0 (1 bit) //!any value --> true
        {
            count++;
        }
        mask = mask >> 1; // shift mask to the right
    }
    return count;
}
// another way to count the number of 1's in an unsigned 32 bits integer
int countSetBits(unsigned int num) // using Brian Kernighan’s Algorithm
{
    int count = 0;
    while (num) // or num != 0
    {
        num = num & (num - 1);
        count++;
    }
    return count;
}

//! ========================== maxOnes ========================================== //
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
//! ========================== maxZeros ========================================== //
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

//! ========================== maxZerosBetween ====================================== //
// function to count the maximum number of consecutive 0's //!between 1’s in an unsigned 32 bits integer
int maxZerosBetween(int num)
{
    int max = 0;
    int count = 0;
    unsigned int mask = 0x80000000; // 32 bits mask
    for (int i = 1; i <= INT_SIZE; i++)
    {
        if (num & mask) // the result is a any value other than 0 (1 bit) //!any value --> true
        {
            //! we only set max once we have a 0 bit after a 1 bit
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
// test case
// unsigned int num = 0b10110101000111000011111100100000;
// Max consecutive 1's 6
// Max consecutive 0's 5
// Max consecutive 0's between 1's 4

//! ========================== Bit operations ====================================== //
// Function to set the kth bit of num // 1 -> 1, 0 -> 1
int setBit(int num, int k)
{
    return (num | (1 << k)); //  OR with 1
}

// Function to clear the kth bit of num // 0 -> 0, 1 -> 0
int clearBit(int num, int k)
{
    return (num & (~(1 << k))); //  AND with 1 complement
}

// Function to toggle the kth bit of num // 0 -> 1, 1 -> 0
int toggleBit(int num, int k)
{
    return (num ^ (1 << k)); // XOR with 1
}

// Function to find the kth bit of num
int findBit(int num, int k)
{
    return ((num >> k) & 1); //  Right shift k times and AND with 1
}

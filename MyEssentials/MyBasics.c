#include <stdio.h>

//! ========================== Swap (using pointers) ==============================  //
void swapAdvanced(int *num1, int *num2) // with no temp variable
{
	*num1 = *num1 ^ *num2;
	*num2 = *num1 ^ *num2;
	*num1 = *num1 ^ *num2;
}
//?? using this method, there is a risk of overflow if the sum of the numbers is greater than the maximum value that can be stored by an integer.
//! ========================== Swap (temp) =========================================  //
void swap(int *num1, int *num2) // using temp variable
{
	int temp;
	temp = *num1;  // save the value of num1
	*num1 = *num2; // assign the value of num2 to num1
	*num2 = temp;  // assign the saved value of num1 to num2
}
//! ========================== SwapPointers (temp) =================================  //
void swapPointers(int **ptr1, int **ptr2) // using temp variable
{
	int *temp;
	temp = *ptr1;  // save the value of ptr1 (address of num1) to temp
	*ptr1 = *ptr2; // assign the value of ptr2 (address of num2) to ptr1
	*ptr2 = temp;  // assign the saved value of ptr1 (address of num1) to ptr2 (address of num2)
}

//! ========================== Power of two ========================================  //
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
//! ========================== isPowerOfTwo (bitwise) ==============================  //
int isPowerOfTwo_(int num) // time complexity: O(1)
{
	// num will check if num == 0 and !(num & (num - 1)) will check if num is a power of 2 or not
	return (num && !(num & (num - 1))); // ( num && ) is to check if num == 0 or not
}
//! ========================== fibonacci of nth ============================  //
int fibOfN(int num) // Recursive approach
{
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
void printFibonacci(int num) // Iterative approach
{
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

//! ========================== isPrime ================================ //
int isPrime(int num) // optimized function to check if num is prime
{
	int i;
	if (num == 2) // 2 is prime //! the only even prime number
	{
		return 1; // prime
	}

	if (num == 0 || num == 1 || num % 2 == 0) // 0 and 1 are not prime and all even numbers are not prime except 2
	{
		return 0; // not prime
	}

	// i = i + 2 to skip even numbers since all even numbers are not prime except 2
	// sqrt(num) is the square root of num
	for (i = 3; i <= sqrt(num); i = i + 2) // alternatively, we can use i <= num / 2
	{
		if (num % i == 0)
		{
			return 0; // not prime
		}
	}
	return 1;
}

//?============================== Bit Manipulation =========================================================

/*
 * Masking Techniques:
 *
 * unsigned int maskMSB = 1 << (sizeof(num) * 8 - 1); // (Loop from MSB) and use mask >>= 1
 * - on using this method, we can just check if the mask is 0 or not to know if we have reached the end of the number
 * - it's better to use this method for PrintBinary function to print the binary number in the correct order
 * - on using this method, we will have to loop while(mask) and use mask >>= 1
 *
 * unsigned int maskLSB = 1;                          // (Loop from LSB) and use mask <<= 1
 * - on using this method, we will have to loop using sizeof(num) * 8 times (using a for loop) to reach the end of the number
 *   where in the previous method, we will loop only until the mask is 0
 */

//! ========================== PrintBinary ========================================== //
void PrintBinary(unsigned char num)
{
	// print the binary number is reverse order (wrong order)
	// int i;
	// unsigned int mask = 1;
	// for (i = 0; i < sizeof(char) * 8; i++)
	// {
	//     if (num & mask)
	//         printf("1");
	//     else
	//         printf("0");
	//     mask <<= 1;
	// }

	unsigned int mask = 1u << (sizeof(num) * 8 - 1);
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

//! ========================== countSetBits (ones) ========================================== //
// function to count the number of 1's in an unsigned 32 bits integer
int countOnes(int num)
{
	int count = 0;
	unsigned int mask = 1u << (sizeof(num) * 8u - 1u); // mask to check the MSB bit

	while (mask)
	{
		if (num & mask) // the result is a any value other than 0 (1 bit) //!any value --> true
		{
			count++;
		}
		mask >>= 1; // shift mask to the right
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
		count++; // number of iterations = number of 1's
	}
	return count;
}

//! ========================== reverseBits ========================================== //
// Function to reverse bits of a given integer
unsigned char Reverse_8Bits(unsigned char num)
{
	unsigned int rev = 0;
	// for (int i = 0; i < sizeof(num) * 8; i++) // old method
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
//! ========================== maxOnes ========================================== //
// function to count the maximum number of consecutive 1's in an unsigned 32 bits integer
int maxOnes(int num)
{
	int max = 0;
	int count = 0;
	unsigned int mask = 1u << (sizeof(num) * 8u - 1u);

	// unsigned int mask = 1;              // 32 bits mask
	// for (int i = 1; i <= INT_SIZE; i++) // old method
	while (mask)
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
		mask >>= 1; // shift mask to the right
	}
	return max;
}
//! ========================== maxZeros ========================================== //
// function to count the maximum number of consecutive 0's in an unsigned 32 bits integer
int maxZeros(int num)
{
	int max = 0;
	int count = 0;
	unsigned int mask = 1u << (sizeof(num) * 8u - 1u);

	unsigned char leadingZeroFlag = 0; // flag to check if the first bit is 0 or not

	// unsigned int mask = 1; | for (int i = 1; i <= INT_SIZE; i++) // old method
	while (mask)
	{
		if (num & mask) // the result is a any value other than 0 (1 bit) //!any value --> true
		{
			count = 0;			 // reset count
			leadingZeroFlag = 1; // set flag to 1
		}
		else // if bit is exactly 0
		{
			if (leadingZeroFlag == 1) // only count zeros after the first 1
			{
				count++;
				if (count > max)
				{
					max = count;
				}
			}
		}
		mask >>= 1; // shift mask to the right
	}
	return max;
}

//! ========================== maxZerosBetween ====================================== //
// function to count the maximum number of consecutive 0's //!between 1’s in an unsigned 32 bits integer
int maxZerosBetween(int num)
{
	int max = 0;
	int count = 0;
	unsigned int mask = 1u << (sizeof(num) * 8u - 1u);

	// unsigned int mask = 1; // 32 bits mask
	// for (int i = 1; i <= INT_SIZE; i++)
	while (mask)
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
		else // if bit is exactly 0
		{
			count++;
		}

		mask >>= 1;
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

//! ========================== MSB ====================================== //
// Function to find the MSB one bit of num
// The MSB of any number is also the nearest power of 2 to that number
int findMSB_one(int num) // left most 1 bit
{
	unsigned int r = 0; // r will be lg(v)
	while (num >>= 1)
	{
		r++;
	}
	return r;
	// this will return only the position (index) of the MSB
	// Ex: 0b10000 --> 4
	// we can later use this value to find the MSB by shifting 1 to the left by r
}
//! ========================== LSB ====================================== //
// Function to find the LSB one bit of num
int findLSB_one(int num) // right most 1 bit
{
	return (num & (-num)); // AND with 2's complement
						   // this will return the value of the LSB
						   // Ex: 0b10000
}
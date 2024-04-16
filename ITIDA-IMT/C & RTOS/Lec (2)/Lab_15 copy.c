#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

void PrintBinary(uint32_t n)
{
	for (int i = 31; i >= 0; i--)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
}

uint32_t reverseBits(uint32_t n)
{
	uint32_t reversedNumber = 0;

	for (int i = 0; i < 32 || n; ++i)
	{
		reversedNumber |= (n & 1) << (31 - i);
		//reversedNumber = (reversedNumber << 1) | (n & 1);

		n >>= 1;
	}

	return reversedNumber;
}

uint32_t reverseBits_2(uint32_t n)
{
	n = (n & 0xAAAAAAAA) >> 1 | (n & 0x55555555) << 1;
	n = (n & 0xCCCCCCCC) >> 2 | (n & 0x33333333) << 2;
	n = (n & 0xF0F0F0F0) >> 4 | (n & 0x0F0F0F0F) << 4;
	n = (n & 0xFF00FF00) >> 8 | (n & 0x00FF00FF) << 8;
	n = (n & 0xFFFF0000) >> 16 | (n & 0x0000FFFF) << 16;
	return n;
}

void test_reverseBits()
{
	assert(reverseBits(4294967293) == 3221225471); // 0xFFFFFFFD
	assert(reverseBits(0) == 0);				   // 0x0
	assert(reverseBits(1) == 2147483648);		   // 0x1
	assert(reverseBits(43261596) == 964176192);	   // 0x2C8590
	assert(reverseBits(2863311530) == 1431655765); // 0xAAAAAAAA
	assert(reverseBits(1431655765) == 2863311530); // 0x55555555
	printf("All tests passed.\n");
}

int main()
{
	test_reverseBits();

	return 0;
}
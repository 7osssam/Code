#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

bool isPowerOfThree(int n)
{
	if (n <= 0)			// 0 is not a power of 3
	{
		return false;
	}
	while (n != 1)		// while number is not 1
	{
		if (n % 3 != 0) // if number is not divisible by 3
		{
			return false;
		}
		n /= 3;			// divide number by 3
	}
	return true;
}

void test_is_power_of_three()
{
	assert(isPowerOfThree(3) == true);	 // 3^1 = 3
	assert(isPowerOfThree(9) == true);	 // 3^2 = 9
	assert(isPowerOfThree(27) == true);	 // 3^3 = 27
	assert(isPowerOfThree(1) == true);	 // 3^0 = 1
	assert(isPowerOfThree(2) == false);	 // Not a power of three
	assert(isPowerOfThree(10) == false); // Not a power of three
	assert(isPowerOfThree(0) == false);	 // Not a power of three
	printf("All tests passed.\n");
}

int main()
{
	int number;
	printf("Enter a number: ");
	scanf("%d", &number);

	int result = isPowerOfThree(number);
	if (result == true)
	{
		printf("%d is a power of 3\n", number);
	}
	else
	{
		printf("%d is not a power of 3\n", number);
	}
	return 0;
}
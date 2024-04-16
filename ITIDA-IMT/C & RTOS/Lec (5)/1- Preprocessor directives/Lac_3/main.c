// tesing bit math functions

#include "bit_math.h"
#include <stdio.h>
#include <assert.h>

void test_BitMath()
{
	unsigned int test_var = 0;

	// 0000 0000 -> 0000 0100 (4)
	SET_BIT(test_var, 2);
	assert(test_var == 4);

	// 0000 0100 -> 0000 0000 (0)
	CLEAR_BIT(test_var, 2);
	assert(test_var == 0);

	// 0000 0000 -> 0000 0100 (4)
	TOGGLE_BIT(test_var, 2);
	assert(test_var == 4);

	// 0000 0100 -> 0000 0000 (0)
	TOGGLE_BIT(test_var, 2);
	assert(test_var == 0);

	printf("All tests passed\n");
}
int main()
{
	test_BitMath();
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <assert.h>

char* reverseLastTwoLetters(char* str)
{
	int len = strlen(str);
	if (len < 2) // if the string has less than 2 characters, invalid input
	{
		return -1;
	}

	static char result[4];	  // static to keep the result after the function returns
	result[0] = str[len - 1]; // last character
	result[1] = ' ';
	result[2] = str[len - 2]; // second last character
	result[3] = '\0';
	return result;
}

void test_reverseLastTwoLetters()
{
	char* result = reverseLastTwoLetters("bat");
	assert(strcmp(result, "t a") == 0);

	result = reverseLastTwoLetters("Hossam");
	assert(strcmp(result, "m a") == 0);

	result = reverseLastTwoLetters("Hossam Mohamed");
	assert(strcmp(result, "d e") == 0);

	result = reverseLastTwoLetters("a");
	assert(result == -1);

	printf("All tests passed\n");
}

int main()
{
	test_reverseLastTwoLetters();
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int str_len(char *str)
{
	int i;
	for (i = 0; str[i] != 0; i++)
		; //  while(str[i++] != 0);
	return i;
}

void str_print(char *str) //! same as printf("%s" , str);
{
	int i;
	for (i = 0; str[i] != 0; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n"); // new line
}

void str_scan(char *str) //! same as gets(str);
{
	int i;
	for (i = 0;; i++)
	{
		scanf("%c", &str[i]);
		if (str[i] == '\n')
			break; // break when you reach new line
	}
	str[i] = 0; // null at the end
}

void str_rev(char *str)
{
	int size = str_len(str), i;
	char temp;
	for (i = 0; i < size / 2; i++)
	{
		temp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = temp;
	}
}

void str_copy(char *strFrom, char *strTO)
{
	int i = 0;
	for (i = 0; strFrom[i] != 0; i++)
	{
		strTO[i] = strFrom[i];
	}
	strTO[i] = 0; //! null at the end
}

void findlongestWord(char *str, char *word)
{
	int i, count = 0, max = 0, indexOfMax;
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] != ' ')
		{
			count++;
			if (count > max)
			{
				max = count;
				indexOfMax = i - max + 1; // i is the index of the last char in the word and max is the length of the word
			}
		}
		else
		{
			count = 0; // reset the counter
		}
	}

	// for ( i = indexOfMax; i < indexOfMax+max; i++)
	// {
	// 	printf("%c" , str[i]);
	// }
	for (i = 0; i < max; i++) //
	{
		word[i] = str[i + indexOfMax]; // copy the word from the string to the word
	}
	word[i] = 0; //! null at the end
}

int str_comp(char *str1, char *str2)
{
	int flag = 1, i;		  // equal by default
	for (i = 0; str1[i]; i++) // if( i =0 ; str1[i] || str2[i] ; i++) it will loop on the longest string
	{
		if (str1[i] != str2[i])
		{
			flag = 0; // not equal
		}
	}
	if (str2[i] != 0) // if str2 is longer than str1
	{
		flag = 0; // not equal
	}
	return flag; // return 1 if equal and 0 if not equal
} //! this condition in for loop " str[i] != 0 " can be replaced by " str[i] " because 0 is false and any other number is true

void IntTostr(int num, char *str)
{
	int i, j, rem, temp, size;
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		for (i = 0; num > 0; i++)
		{
			rem = num % 10;
			str[i] = rem + '0'; // '0' char + int num = char of num
			num = num / 10;
		} // the result is reversed number

		for (j = 0; j < (i - 1) / 2; j++)
		{
			temp = str[i - 1 - j];
			str[i - 1 - j] = str[j];
			str[j] = temp;
		}

		str[i] = 0; //! null at the end
	}
}

int strToInt(char *str)
{
	int i = 0, intger = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			intger = intger * 10 + (str[i] - '0');
	}
	return intger;
}

int main()
{
	char str[] = "Ahmed";
	char word[50];
	str_print(str);
	printf("%d \n", str_len(str));
	findlongestWord(str, word);
	str_print(word);
	return 0;
}
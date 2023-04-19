//? https://www.hackerrank.com/challenges/frequency-of-digits-1/problem
// frequency of digits in a string

#include <stdio.h>

int main()
{
    char str[10000];         // limit of string length is 10000
    int frequency[10] = {0}; // frequency of digits 0-9

    gets(str); // read string

    for (int i = 0; str[i] != '\0'; i++) // loop through string
    {
        if (str[i] >= '0' && str[i] <= '9') // check if character is a digit
        {
            int num = str[i] - '0'; // convert character to integer

            frequency[num]++; // increment frequency of digit by 1 (num is the index of the digit)
        }
    }

    for (int i = 0; i < 10; i++) // print frequency of digits
    {
        printf("%d ", frequency[i]);
    }

    return 0;
}

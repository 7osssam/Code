//? https://www.hackerrank.com/challenges/printing-tokens-/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char *s;
    s = malloc(1024 * sizeof(char)); // memory allocation for the string
    scanf("%[^\n]", s);              // taking input of the string with spaces using %[^\n] format specifier
    s = realloc(s, strlen(s) + 1);   // memory reallocation for the string to remove the extra spaces allocated by malloc

    //////////////!
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            printf("\n");
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    //////////////!

    return 0;
}

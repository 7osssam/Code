/******************************************************************************
(11)Write a function that prints the frequency of a certain character in a string.
*******************************************************************************/
#include <stdio.h>

int freqOfChar(char *str, char ch)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
            count++;
    }
    return count;
}
int main()
{
    char str[] = "this is a test ";
    char ch;
    scanf("%c", &ch);
    printf("%d", freqOfChar(str, ch));
    return 0;
}
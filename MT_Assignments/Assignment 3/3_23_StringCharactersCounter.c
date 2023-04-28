/******************************************************************************
(23) Write a C function to find the frequency of characters in a string.
• Input the string from the user.
• Traverse the string, character by character and store the count of each of the characters in an array.
• Print the array that contains the frequency of all the characters.
*******************************************************************************/
#include <stdio.h>
int charactersCounter(char *str, unsigned int *chFreq)
{
    int i, j;
    for (i = 0; str[i] != '\0'; i++)
    {
        chFreq[str[i]]++;
    }
    return i;
}
int main()
{
    char str[256];
    unsigned int chFreq[256] = {0};

    gets(str);
    int OutputSize = charactersCounter(str, chFreq);

    for (int i = 0; i < 256; i++)
    {
        if (chFreq[i] != 0)
        {
            printf("%c %d\n", i, chFreq[i]);
        }
    }

    return 0;
}
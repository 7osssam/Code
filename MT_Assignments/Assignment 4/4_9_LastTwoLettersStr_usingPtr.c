// (9) Given a string, create a new string made up of its last two letters,
// reversed and separated by a space, the word is “bat”. Return string contains ”t a”

#include <stdio.h>

int main()
{
    char str[100];
    char OutputStr[4];
    char *Ptr = str;

    gets(str);

    while (*Ptr != '\0') // while the pointer doesn't point to the null character
    {
        Ptr++;
    }

    OutputStr[0] = *(--Ptr); // decrement the pointer to point to the last character

    OutputStr[1] = ' '; // add a space

    OutputStr[2] = *(--Ptr); // decrement the pointer to point to the second last character

    OutputStr[3] = 0; // add the null character

    puts(OutputStr);
}
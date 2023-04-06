//  (14) Write a program to display English alphabets from A to Z.

#include <stdio.h>

int main()
{
    char c;
    // instial value of c is 'A' and it will be incremented until it reaches 'Z'
    for (c = 'A'; c <= 'Z'; c++)
    {
        printf("%c ", c); // print the character
    }
}
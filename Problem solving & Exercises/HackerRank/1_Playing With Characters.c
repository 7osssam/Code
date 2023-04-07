//! hackerrank.com/challenges/playing-with-characters/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char ch;
    char s[20], sen[100];
    scanf("%c", &ch);
    scanf("%s", s);
    scanf("\n");
    scanf("%[^\n]%*c", sen); // %[^\n] means take input until new line is encountered. Then, with this %*c, it reads the new line character and here, the used * indicates that this new line character is discarded.
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);
    return 0;
}

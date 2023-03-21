#include <stdio.h>

int main()
{
    char x[] = "abc\0xyz";
    printf("%s\n", x);

    return 0;
}

//output is abc because the \0 is
//character that tells it is end
//of the string
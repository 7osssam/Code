#include <stdio.h>

int main()
{
    if (printf("Hi\t"))
    {
        printf("hello\n");
    }
    else
    {
        printf("bye\n");
    }

    return 0;
}

// output is Hi  hello, because
// printf return type is Integer
// and returns 3 because hi and an
// escape charecter
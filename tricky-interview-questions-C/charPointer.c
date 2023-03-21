#include <stdio.h>

int main()
{
    char *p;
    printf(" char pointer :%d\n, char type: %d\n", sizeof(*p), sizeof(p));
    

    return 0;
}

//output is char pointer: 1 bytes
//and char pointer : 4 or 2 bytes depending on the size of the compiler
 
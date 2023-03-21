#include <stdio.h>

int main()
{
    int *p;
    float *q;
    double *r;
    char *s;
    printf(" int pointer :%d\n", sizeof(p));
    printf(" float pointer :%d\n", sizeof(q));
    printf(" double pointer :%d\n", sizeof(r));
    printf(" char pointer :%d\n", sizeof(char *));
    

    return 0;
}

//output is 2 bytes or 4 bytes depending 
//upon the size of the compiler 
//whether it is  16 bit or 32 bit.
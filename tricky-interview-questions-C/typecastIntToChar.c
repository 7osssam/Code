#include <stdio.h>
#define int char

int main()
{
    int i = 65;
    //clrscr();
    printf(" size of(i) : %d\n", sizeof(i));
    
}

//output is 1, since we typcasted int as char
//it takes one byte
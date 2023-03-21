#include <stdio.h>

int main()

{
   char *str = "nareshit";
   printf("%c\n", *((str--+2)+1)-3);
   printf("%c\n", *(--str+3)-32);
   printf("%c\n", *(++str+2)+4);
    return 0;
}

//output is b, A, e
//paranthesis has highest priority over
//the dereferencing operator

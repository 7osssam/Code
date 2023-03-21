#include <stdio.h>

int main()

{
   int const *p = 5;
   printf("%d\n", ++(*p));
    return 0;
}

//there is a compile time error
//increment or decrement cannot be done on the
//read-only location

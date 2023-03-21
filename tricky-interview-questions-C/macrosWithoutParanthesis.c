#include <stdio.h>

#define square(x) x*x

int main()

{
  
 
    int i, j;
    i = 64/square(4);
    printf("%d\n", i);
    return 0;
    
}

//output is 64
//when we define macros, we need to put them in parenthesis
//so  64/ 4*4  gets substituted
// according to the priority
// the division has highest priority
// 64 / 4 = 16
// 16 * 4 = 64
// hence, 64 is the answer

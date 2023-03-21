#include <stdio.h>

#define square(x) ((x)*(x))

int main()

{
  
 
    int i, j;
    i = 64/square(4);
    printf("%d\n", i);
    return 0;
    
}

//output is 4
//when we define macros, we need to put them in parenthesis
//so  64/ (4*4)  gets substituted
// according to the priority
// the parenthesis has highest priority
// 64 / (4*4) = 64 / 16
// 64 / 16 = 4
// hence, 4 is the answer

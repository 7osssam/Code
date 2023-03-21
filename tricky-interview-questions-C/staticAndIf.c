#include <stdio.h>

int main()
{
    static int var = 5;
    printf("var is %d\n", var--);
    if(var)
        main();
    return 0;
}

//output is 5  4  3  2  1
// even though we have static 
//varible the new value gets updated

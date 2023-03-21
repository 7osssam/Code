#include <stdio.h>

int main()
{
    int i =5;
    int j = (i+1,  i+2, i+3,i+4);
    printf("i is%d\n", i);
    printf("j is%d\n", j);

    return 0;
}
//j value is 12, because the final expression gets assigned to j
//i value remains same 5 because we did not assign it finally.
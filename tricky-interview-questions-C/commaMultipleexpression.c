#include <stdio.h>

int main()
{
    int i =5;
    int j = (i =i+1,  i =i+2, i=i+3,i+4);
    printf("i is%d\n", i);
    printf("j is%d\n", j);

    return 0;
}
//j value is 15, because the final expression gets assigned to j
//i value remains same 11 because we did not assign it finally.
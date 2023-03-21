#include <stdio.h>

int main()
{
    int i;
    for(i = 0; i <=5; i++)
    {
        if(i == 4)
        continue;
        printf("%d\n", i);
    }

    return 0;
}

//basically, continue statement is like a pass and ignores
//the rest of the code and the control goes to the for loop
// Output: 0,1,2,3,5
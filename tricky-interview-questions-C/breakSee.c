#include <stdio.h>

int main()
{
    int i;
    for(i = 0; i <=5; i++)
    {
        if(i == 4)
        break;
        printf("%d\n", i);
    }

    return 0;
}

//basically, break statement is break condition and ignores
//the rest of the code and the control goes outside the for loop
//Output: 0,1,2,3
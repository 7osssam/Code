#include <stdio.h>

int main()
{
    int x =2;
    switch(x)
    {
        case 1:
        printf("c\n");
        case 2:
        printf("c++\n");
        case 3:
        printf("java\n");
        default:
        printf("python\n");
    }

    return 0;
}

//output is C++ java python, because once the match is found that
//particular part executes. However, since there is no break is not used
//so, all the statements are executed.
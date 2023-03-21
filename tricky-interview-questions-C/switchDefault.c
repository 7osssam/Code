#include <stdio.h>

int main()
{
    int x =2;
    switch(4)
    {
        case 1:
        printf("c\n");
        case 2:
        printf("c++\n");
        case 3:
        printf("java\n");
    }

    return 0;
}

//no visible statement is output, because no match is found
// and there is no default case.
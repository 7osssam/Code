#include <stdio.h>

int main()
{
    int i;
    if(i= printf("hello"))
    {
        printf("A %d\n", i);
    }
    else
    {
        printf("B %d\n", i);
    }

    return 0;
}

//Output is hello A 5. The if conditonal
//statment evaluates to True for a non-zero value
//so, the i value is 5 because hello has 5 charecters.
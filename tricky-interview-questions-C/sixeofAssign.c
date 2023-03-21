#include <stdio.h>

int main()
{
    int i =5;
    printf("%d\t", sizeof(i=3));
    

    printf("i vakue is: %d", i);

    return 0;
}

//output is 3 and i value is 5, because
//the sizeof operator gives 2 or 4 depending 
//upon the size of the compiler.
//the assignment operator has no effect
//on the i value in this case.
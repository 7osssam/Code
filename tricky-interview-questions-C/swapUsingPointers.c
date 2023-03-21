#include <stdio.h>

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{
    
    int a = 5, b =4;
    printf("before swap a is %d, b is %d\n", a ,b);
    swap(&a, &b);
    printf("after swap a is %d, b is %d\n", a ,b);
    return 0;
}
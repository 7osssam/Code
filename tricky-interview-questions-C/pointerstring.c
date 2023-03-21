#include <stdio.h>

int main()
{
    int* k = 541;
    printf("%d\n", k);
    *k = 'a';
    printf("%s\n", k);
    return 0;
}
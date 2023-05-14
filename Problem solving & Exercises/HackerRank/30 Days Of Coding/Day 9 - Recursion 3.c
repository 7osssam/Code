#include <stdio.h>

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int num;
    scanf("%d", &num);

    factorial(num);

    printf("%d", factorial(num));
}
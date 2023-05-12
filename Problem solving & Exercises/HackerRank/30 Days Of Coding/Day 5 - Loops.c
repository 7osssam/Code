
#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    for (int i = 1; i <= 10; i++)
    {
        // n x i = result
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}

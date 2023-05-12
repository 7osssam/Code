#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void strFun(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (i % 2 == 0)
        {
            printf("%c", s[i]);
        }
    }

    printf(" ");

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (i % 2 != 0)
        {
            printf("%c", s[i]);
        }
    }

    printf("\n");
}

int main()
{
    int n;
    char str[10000];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        strFun(str);
    }
}

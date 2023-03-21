#include <stdio.h>

#define square(x) ((x)*(x))

int main()

{
    int n;
    printf("enter a number between 1 and 7\n");
    scanf("%d", &n);
    switch(n)
    {
        case 1: printf("Sunday\n");
                break;
        case 2: printf("Monnday\n");
                break;
        case 3: printf("Tuesday\n");
                break;
        case 4: printf("Wednesday\n");
                break;
        case 5: printf("Thursday\n");
                break;
        case 6: printf("Friday\n");
                break;
        case 7: printf("Saturday\n");
                break;
        default: printf("wrong number\n");
                break;
    }
    return 0;
}


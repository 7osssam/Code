#include <stdio.h>

int main()
{
    char ch = '*';
    switch(ch)
    {
        case '*': printf("%c\t", ch);
        case '?': printf("%c\t", ch);
        default:  printf("%c\t", '*');

    }
    return 0;
}

//output is * * *
//according to the condition the case * should execute
//however, there is no break statement all the other cases gets
//executed as well
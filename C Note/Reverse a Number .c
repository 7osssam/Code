#include <stdio.h>
#include <stdlib.h>

int reverse(int num )
{
    int mod ,rev=0;
    while (num != 0)
    {
        mod = num %10;
        rev = rev *10 + mod;
        num   = num /10;
    }
    return rev;
}
int main() {
    int num = 7891;

    printf("%d" , reverse(num));

  return 0;
    }

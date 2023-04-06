#include <stdio.h>

int gcd(int num1, int num2)
{
    int gcd;
    for (size_t i = 1; i <= num1 && i <= num2; i++) // time complexity: o(n)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            gcd = i;
        }
    }

    // another method // Euclidean algorithm // time complexity: O(log(n)) //better than above

    // while (num1 != num2)
    // {
    //     if (num1 > num2)
    //     {
    //         num1 -= num2;
    //     }
    //     else
    //     {
    //         num2 -= num1;
    //     }
    // }
    // gcd = num1;

    return gcd;
}

int lcm(int num1, int num2)
{
    return (num1 * num2) / gcd(num1, num2);
}

int main()
{
    int num1, num2, result;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    result = lcm(num1, num2);

    printf("LCM of %d and %d is %d\n", num1, num2, result);

    return 0;
}

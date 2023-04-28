// 18 - Given a positive integer z, check if z can be written as 𝑝^𝑞 (p power of q),
// where p and q are positive integers than 1,
// if z can be written as 𝑝𝑞 return 1 else return 0.
// Description: A positive integer that needs to be determined if it can be expressed as a power of square number.

//? In other words, you need to determine whether z can be written as a power of a square number
//? the square root of the number * the square root of the number == the number

#include <stdio.h>
#include <math.h>

int superPower(int z)
{
    int result;
    result = (int)sqrt(z);
    if (z == (result * result))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int num, res;
    scanf("%d", &num);
    res = superPower(num);
    if (res == 1)
    {
        printf("The input number %d is super square \n", num);
    }
    else
    {
        printf("The input number %d is not super square \n", num);
    }
    return 0;
}
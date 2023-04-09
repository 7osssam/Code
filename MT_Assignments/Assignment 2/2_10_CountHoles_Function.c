// 10 - You are designing a poster which prints out numbers with a unique style applied to each of them.
// The styling is based on the number of closed paths or holes present in a giver number.
// The number of holes that each of the digits from 0 to 9 have are equal to the number of closed paths in the digit.
// Their values are:
// •1, 2, 3, 5 and 7 = 0 holes.
// •0, 4, 6, and 9 = 1 hole.
// •8 = 2 holes.
// Given a number, you must determine the sum of the number of holes for all of its digits.
// For example, the number 819 has 3 holes.Function DescriptionComplete the function countHoles.
// The function must return an integer denoting the total number of holes in num.

#include <stdio.h>

int CountHoles(int num)
{
    switch (num)
    {
    case 1:
    case 2:
    case 3:
    case 5:
    case 7:
        return 0;
        break;

    case 0:
    case 4:
    case 6:
    case 9:
        return 1;
        break;
    case 8:
        return 2;
        break;
    default:
        return -1; // not a number
        break;
    }
}

int main()
{
    int num;
    int mod;
    int result = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0)
    {
        mod = num % 10;
        result = result + CountHoles(mod);
        if (result == -1)
        {
            printf("Wrong input");
        }

        num = num / 10;
    }
    printf("%d Holes", result);
}
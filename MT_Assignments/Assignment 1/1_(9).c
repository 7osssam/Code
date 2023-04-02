// (9) Write a program that reads a student grade percentage and prints
//"Excellent" if his grade is greater than or equal 85,
//"Very Good" for 75 or greater;
//"Good" for 65,
//"Pass" for 50, "Fail" for less than 50.

#include <stdio.h>

int main()
{
    int grade;

    printf("Enter grade ");
    scanf("%d", &grade);

    if (grade >= 85) // Excellent if grade is greater than or equal to 85
    {
        printf("Excellent");
    }
    else if (85 > grade && grade >= 75) // Very Good if grade is greater than 75 and less than 85
    {
        printf("Very Good");
    }
    else if (75 > grade && grade >= 65) // Good if grade is greater than 65 and less than 75
    {
        printf("Good");
    }
    else if (65 > grade && grade >= 50) // Pass if grade is greater than 50 and less than 65
    {
        printf("Pass");
    }
    else if (grade < 50) // Fail if grade is less than 50
    {
        printf("Fail");
    }

    return 0;
}
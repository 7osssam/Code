// (3) Write a program for converting temperature from
// degrees Celsius to degrees Fahrenheit,
// given the formula:

// F = C x  9/5  + 32

#include <stdio.h>

int main()
{
    float Celsius, Fahrenheit;                    // Declaring two variables
    printf("Enter the temperature in Celsius: "); // Printing a message
    scanf("%f", &Celsius);                        // Taking a float from the user

    Fahrenheit = (Celsius * 9 / 5) + 32; // Converting Celsius to Fahrenheit
    printf("%.2f", Fahrenheit);          // Printing the result

    return 0;
}

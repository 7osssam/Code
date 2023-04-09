// 12 - Write a C function that calculates the required heater activation time according to the input temperature of water.
// -if input temperature is from 0 to 30, then required heating time = 7 mins.
// -if input temperature is from 30 to 60, then required heating time = 5 mins.
// -if input temperature is from 60 to 90, then required heating time = 3 mins.
// -if input temperature is more than 90, then required heating time = 1 mins.
// -if temperature is invalid (more than 100), return 0
// Example:
// Input = 10 →output = 7
// Input = 35 →output = 5

#include <stdio.h>
int heatTime(int num)
{
    int time;
    if (0 <= num && num < 30)
    {
        time = 7;
    }
    else if (30 < num && num <= 60)
    {
        time = 5;
    }
    else if (60 < num && num <= 90)
    {
        time = 3;
    }
    else if (90 < num && num < 100)
    {
        time = 1;
    }
    else
    {
        time = 0; // invalid
    }
    return time;
}
int main()
{
    int temperature;

    printf("Enter temperature : ");
    scanf("%d", &temperature);

    printf("if temperature = %d then time = %d", temperature, heatTime(temperature));
}
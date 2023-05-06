/*
Create enum type called fan_level it shall have three values Level1, Level2 and Level3.
This enum shall be used to control the level of the fan.
*/

#include <stdio.h>
enum fan_level
{
    level1 = 1,
    level2,
    level3
};

int main()
{
    enum fan_level fan1;

    fan1 = level1;
    printf("Level1 = %d\n", fan1);

    fan1 = level2;
    printf("Level2 = %d\n", fan1);

    fan1 = level3;
    printf("Level3 = %d\n", fan1);
}
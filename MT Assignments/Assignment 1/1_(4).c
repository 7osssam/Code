// (4) Write a program that reads the radius of a circle and
// calculates the area and circumference then prints the
// results.

#include <stdio.h>
#define Pi 3.1415 // Defining a constant
int main()
{
    int radius;
    float circumference, area;

    printf("Enter radius:");
    scanf("%d", &radius);

    circumference = 2 * Pi * radius;
    area = Pi * radius * radius;

    printf("circumference=%.2f\narea=%.2f", circumference, area);

    return 0;
}
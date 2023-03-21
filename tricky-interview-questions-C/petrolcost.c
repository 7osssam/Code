#include <stdio.h>

int main()
{
    float km = 45.00, litre = 1.00, cost = 30.00, number_of_litres= 0, coverage_cost= 0;
    int coverage_in_km = 120;
    printf("the bike runs %f for 1 litre of Petrol\n", km);
    printf("enter the number of Kilometers to be travelled\n");
    scanf("%d", &coverage_in_km);
    number_of_litres = coverage_in_km/km;
    coverage_cost = number_of_litres * cost;
    printf("%f cost is needed to run the bike for %d kilometer\n", coverage_cost, coverage_in_km);
    return 0;
}
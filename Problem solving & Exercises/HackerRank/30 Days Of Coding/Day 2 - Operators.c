
#include <stdio.h>

void solve(double meal_cost, int tip_percent, int tax_percent)
{
    double tip = meal_cost * tip_percent / 100;
    double tax = meal_cost * tax_percent / 100;
    double totalCost = meal_cost + tip + tax;

    printf("%.0lf", totalCost); // or printf("%d", (int)round(totalCost));
}

int main()
{
    double meal_cost;
    int tip_percent;
    int tax_percent;

    scanf("%lf", &meal_cost);
    scanf("%d", &tip_percent);
    scanf("%d", &tax_percent);

    solve(meal_cost, tip_percent, tax_percent);

    return 0;
}

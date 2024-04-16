#include <stdio.h>

int main()
{
	float cost_price;
	float selling_price;
	float profit;
	float loss;

	printf("Enter cost price: ");
	scanf("%f", &cost_price);

	printf("Enter selling price: ");
	scanf("%f", &selling_price);

	if (selling_price > cost_price)
	{
		profit = selling_price - cost_price;
		printf("Profit = %.2f\n", profit);
	}
	else if (cost_price > selling_price)
	{
		loss = cost_price - selling_price;
		printf("Loss = %.2f\n", loss);
	}
	else
	{
		printf("No profit, no loss.\n");
	}

	return 0;
}
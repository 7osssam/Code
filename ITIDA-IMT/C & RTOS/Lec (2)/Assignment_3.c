#include <stdio.h>

int calculate_heating_time(int temperature)
{
	if (temperature >= 0 && temperature < 30)
	{
		return 7;
	}
	else if (temperature >= 30 && temperature < 60)
	{
		return 5;
	}
	else if (temperature >= 60 && temperature < 90)
	{
		return 3;
	}
	else if (temperature >= 90 && temperature <= 100)
	{
		return 1;
	}
	else
	{
		return 0; // Invalid temperature
	}
}

int main()
{
	int temperature;
	printf("Enter the temperature: ");
	scanf("%d", &temperature);

	int heating_time = calculate_heating_time(temperature);
	printf("Required heating time for %d degrees is %d minutes\n", temperature, heating_time);
	return 0;
}
#include <iostream>
#include <cmath>

#define PI 3.14

int main()
{
	double radius;
	std::cout << "Enter the radius of the circle: ";
	std::cin >> radius;

	double area = PI * std::pow(radius, 2);
	double perimeter = 2 * PI * radius;

	std::cout << "Area: " << area << std::endl;
	std::cout << "Perimeter: " << perimeter << std::endl;

	return 0;
}

#include <iostream>
#include <cmath>

#define PI 3.14

int main()
{
	int	   n;
	double s;

	std::cout << "Enter the number of sides: ";
	std::cin >> n;

	std::cout << "Enter the length of each side: ";
	std::cin >> s;

	// ref: https://www.mathopenref.com/polygonarea.html
	// Apothem = [(length of one side)/{2 ×(tan(180/number of sides))}]
	double Apothem = s / (2 * std::tan(PI / n));
	// Area = (number of sides × length of one side × apothem)/2
	double area = (n * s * Apothem) / 2;

	std::cout << "The area of the polygon is: " << area << std::endl;

	return 0;
}

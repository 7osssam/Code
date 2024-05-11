#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Sphere.hpp"
#include <iostream>

/* [Base class --> Derived class]
 * shape.hpp  --> Circle.hpp
 * 			 --> Rectangle.hpp
 * 			 --> Triangle.hpp
 * 
 * ThreeDimensionalShape.hpp --> Sphere.hpp
 */

int main()
{
	Rectangle rectangle("Rectangle", 5.0, 4.0);
	std::cout << rectangle.getName() << " Area: " << rectangle.calculateArea() << std::endl;

	Circle circle("Circle", 3.0);
	std::cout << circle.getName() << " Area: " << circle.calculateArea() << std::endl;

	Triangle triangle("Triangle", 6.0, 7.0);
	std::cout << triangle.getName() << " Area: " << triangle.calculateArea() << std::endl;

	Sphere sphere("Sphere", 3.0);
	std::cout << sphere.getName() << " Area: " << sphere.calculateArea()
			  << ", Volume: " << sphere.calculateVolume() << std::endl;

	return 0;
}
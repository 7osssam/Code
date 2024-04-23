#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Shape.hpp"
#include <iostream>

int main()
{
	Rectangle rectangle("Red", 5.0, 4.0);
	std::cout << "Rectangle Area: " << rectangle.getArea() << std::endl;
	std::cout << "=====================" << std::endl;

	Circle circle("Blue", 3.0);
	std::cout << "Circle Area: " << circle.getArea() << std::endl;
	std::cout << "=====================" << std::endl;

	Triangle triangle("Green", 6.0, 7.0);
	std::cout << "Triangle Area: " << triangle.getArea() << std::endl;
	std::cout << "=====================" << std::endl;

	return 0;
}
#include <iostream>
#include <vector>

#include "ShapeFactory.hpp"

int main()
{
	std::vector<Shape*> shapes = {ShapeFactory::createShape(ShapeType::CIRCLE, 5),
								  ShapeFactory::createShape(ShapeType::RECTANGLE, 4, 5),
								  ShapeFactory::createShape(ShapeType::TRIANGLE, 3, 4)};

	for (auto shape: shapes)
	{
		std::cout << "Area: " << shape->getArea() << ", Perimeter: " << shape->getPerimeter() << std::endl;
	}

	// Don't forget to delete the objects
	for (auto shape: shapes)
	{
		delete shape;
	}

	return 0;
}
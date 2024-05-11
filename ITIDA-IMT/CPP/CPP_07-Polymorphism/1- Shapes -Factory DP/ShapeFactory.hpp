#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"

enum ShapeType
{
	CIRCLE,
	RECTANGLE,
	TRIANGLE
};

class ShapeFactory
{
public:
	static Shape* createShape(ShapeType type, double a, double b = 0)
	{
		switch (type)
		{
			case ShapeType::CIRCLE:
				return new Circle(a);
				break;
			case ShapeType::RECTANGLE:
				return new Rectangle(a, b);
			case ShapeType::TRIANGLE:
				return new Triangle(a, b);
			default:
				return nullptr;
		}
	}
};

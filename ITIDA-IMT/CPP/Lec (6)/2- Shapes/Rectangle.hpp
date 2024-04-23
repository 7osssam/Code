#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Shape.hpp" // Base class

class Rectangle : public Shape
{
private:
	double width;
	double height;

public:
	Rectangle(std::string color, double width, double height) : Shape(color), width(width), height(height)
	{
	}

	double getArea()
	{
		return width * height;
	}
};
#endif // __RECTANGLE_H__
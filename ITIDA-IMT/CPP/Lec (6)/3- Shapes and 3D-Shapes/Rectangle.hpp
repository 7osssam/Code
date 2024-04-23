#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Shape.hpp"

class Rectangle : public Shape
{
private:
	double length;
	double width;

public:
	Rectangle(std::string name, double length, double width) : Shape(name), length(length), width(width)
	{
	}

	double calculateArea() override
	{
		return length * width;
	}
};
#endif // __RECTANGLE_H__
#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Shape.hpp"

class Rectangle : public Shape
{
	double length;
	double width;

public:
	Rectangle(double l, double w) : length{l}, width{w}
	{
	}
	double getArea() override
	{
		return length * width;
	}
	double getPerimeter() override
	{
		return 2 * (length + width);
	}
};
#endif // __RECTANGLE_H__
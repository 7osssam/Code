#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "Shape.hpp"
#include <cmath>

class Triangle : public Shape
{
	double base, height;

public:
	Triangle(double b, double h) : base{b}, height{h}
	{
	}
	double getArea() override
	{
		return 0.5 * base * height;
	}
	double getPerimeter() override
	{
		return base + height + sqrt(base * base + height * height);
	}
};

#endif // __TRIANGLE_H__
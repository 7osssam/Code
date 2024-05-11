#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Shape.hpp"
#include <cmath>

class Circle : public Shape
{
private:
	double radius;

public:
	Circle(std::string name, double radius) : Shape(name), radius(radius)
	{
	}

	double calculateArea() override
	{
		return M_PI * radius * radius;
	}
};
#endif // __CIRCLE_H__
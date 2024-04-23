#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Shape.hpp" // Base class
#include <cmath>

class Circle : public Shape
{
private:
	double radius;

public:
	Circle(std::string color, double radius) : Shape(color), radius(radius)
	{
	}

	double getArea()
	{
		return M_PI * radius * radius;
	}
};
#endif // __CIRCLE_H__
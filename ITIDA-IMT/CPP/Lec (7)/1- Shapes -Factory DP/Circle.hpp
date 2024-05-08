#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Shape.hpp"
#include <cmath>

class Circle : public Shape
{
	double radius;

public:
	Circle(double r) : radius{r}
	{
	}
	double getArea() override
	{
		return M_PI * radius * radius;
	}
	double getPerimeter() override
	{
		return 2 * M_PI * radius;
	}
};
#endif // __CIRCLE_H__
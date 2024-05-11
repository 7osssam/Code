#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "Shape.hpp" // Base class

class Triangle : public Shape
{
private:
	double base;
	double height;

public:
	Triangle(std::string color, double base, double height) : Shape(color), base(base), height(height)
	{
	}

	double getArea()
	{
		return 0.5 * base * height;
	}
};
#endif // __TRIANGLE_H__
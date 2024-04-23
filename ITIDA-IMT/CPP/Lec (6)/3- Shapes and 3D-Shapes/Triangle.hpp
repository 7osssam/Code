#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "Shape.hpp"

class Triangle : public Shape
{
private:
	double base;
	double height;

public:
	Triangle(std::string name, double base, double height) : Shape(name), base(base), height(height)
	{
	}

	double calculateArea() override
	{
		return 0.5 * base * height;
	}
};
#endif // __TRIANGLE_H__
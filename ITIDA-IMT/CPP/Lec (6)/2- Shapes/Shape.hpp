#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <string>

class Shape
{
protected:
	std::string color;

public:
	Shape(std::string color) : color(color)
	{
	}

	virtual ~Shape()
	{
	}

	virtual double getArea() = 0; // virtual function to be overridden (implemented) by derived classes
};
#endif							  // __SHAPE_H__
#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <string>

class Shape
{
protected:
	std::string name;

public:
	Shape(std::string name) : name(name)
	{
	}

	std::string getName()
	{
		return name;
	}

	virtual double calculateArea() = 0; // Pure virtual function
};
#endif									// __SHAPE_H__
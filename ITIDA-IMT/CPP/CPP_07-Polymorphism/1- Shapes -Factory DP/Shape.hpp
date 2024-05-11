#ifndef __SHAPE_H__
#define __SHAPE_H__

// Base class
class Shape
{
public:
	virtual double getArea() = 0;	   // Pure virtual function
	virtual double getPerimeter() = 0; // Pure virtual function
};
#endif								   // __SHAPE_H__
#ifndef __THREEDIMENSIONALSHAPE_H__
#define __THREEDIMENSIONALSHAPE_H__

#include "Shape.hpp"

class ThreeDimensionalShape : public Shape
{
public:
	ThreeDimensionalShape(std::string name) : Shape(name)
	{
	}

	virtual double calculateVolume() = 0;
};
#endif // __THREEDIMENSIONALSHAPE_H__
#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "ThreeDimensionalShape.hpp"
#include <cmath>

class Sphere : public ThreeDimensionalShape
{
private:
	double radius;

public:
	Sphere(std::string name, double radius) : ThreeDimensionalShape(name), radius(radius)
	{
	}

	double calculateArea() override
	{
		return 4 * M_PI * radius * radius;
	}

	double calculateVolume() override
	{
		return (4.0 / 3.0) * M_PI * radius * radius * radius;
	}
};
#endif // __SPHERE_H__
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

class Shape
{
public:
	virtual double area() const = 0;
	virtual double perimeter() const = 0;

	//operator overloading for -> as it's not available for objects when using without pointers for example in line 74
	Shape* operator->()
	{
		return this;
	}
};

// Derived class Circle
class Circle : public Shape
{
private:
	double radius;

public:
	Circle(double radius) : radius(radius)
	{
	}

	double area() const override
	{
		return M_PI * radius * radius;
	}

	double perimeter() const override
	{
		return 2 * M_PI * radius;
	}
};

// Derived class Rectangle
class Rectangle : public Shape
{
private:
	double width;
	double height;

public:
	Rectangle(double width, double height) : width(width), height(height)
	{
	}

	double area() const override
	{
		return width * height;
	}

	double perimeter() const override
	{
		return 2 * (width + height);
	}
};

// Templated function to calculate the total area and perimeter of a collection of shapes
template <typename T>
void calculateTotal(std::vector<T>& shape)
{
	double totalArea = 0.0;
	double totalPerimeter = 0.0;

	for (auto& s: shape)
	{
		//totalArea += s.area();
		//totalPerimeter += s.perimeter();
		totalArea += s->area();
		totalPerimeter += s->perimeter();
	}

	std::cout << "Total area: " << totalArea << std::endl;
	std::cout << "Total perimeter: " << totalPerimeter << std::endl;
	std::cout << "==============================" << std::endl;
}

int main()
{
	std::vector<Shape*> shapes;
	shapes.push_back(new Circle(5.0));
	shapes.push_back(new Circle(10.0));
	shapes.push_back(new Rectangle(4.0, 6.0));
	shapes.push_back(new Rectangle(8.0, 12.0));

	std::vector<Circle> circles;
	circles.push_back(Circle(5.0));
	circles.push_back(Circle(3.0));
	circles.push_back(Circle(2.0));

	std::vector<Rectangle> rectangles;
	rectangles.push_back(Rectangle(4.0, 6.0));
	rectangles.push_back(Rectangle(3.0, 5.0));
	rectangles.push_back(Rectangle(2.0, 4.0));

	calculateTotal<Circle>(circles);
	calculateTotal<Rectangle>(rectangles);
	calculateTotal<Shape*>(shapes);

	// Deallocating of the memory
	for (auto& shape: shapes)
	{
		delete shape;
	}

	return 0;
}
#include <iostream>
#include <string>

// Shape Base Class
class Shape
{
public:
	virtual void draw() const = 0;
};

// Derived Classes

class Circle : public Shape
{
public:
	void draw() const override
	{
		std::cout << "Drawing a circle." << std::endl;
	}
};

class Rectangle : public Shape
{
public:
	void draw() const override
	{
		std::cout << "Drawing a rectangle." << std::endl;
	}
};

// Adding a New Shape

class Triangle : public Shape
{
public:
	void draw() const override
	{
		std::cout << "Drawing a triangle." << std::endl;
	}
};

// ShapeDrawer Class
class ShapeDrawer
{
public:
	void drawShape(const Shape& shape)
	{
		shape.draw();
	}
};

int main()
{
	Circle		circle;
	Rectangle	rectangle;
	ShapeDrawer drawer;
	drawer.drawShape(circle);
	drawer.drawShape(rectangle);

	// Adding a New Shape
	std::cout << "Adding a New Shape" << std::endl;

	Triangle triangle;
	drawer.drawShape(triangle);

	return 0;
}
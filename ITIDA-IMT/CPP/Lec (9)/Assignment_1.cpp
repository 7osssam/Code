#include <vector>
#include <iostream>

template <typename T>
class MyContainer
{
protected:
	std::vector<T> elements_;

public:
	//std::vector<T> elements_;

	//void addElement(const T element)
	void addElement(const T& element) // using & to avoid copying
	{
		elements_.push_back(element);
	}

	virtual void display() const
	{
		std::cout << "Base: MyContainer: ";

		for (const auto& element: elements_)
		{
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
};

template <typename T>
class DerivedContainer : public MyContainer<T>
{
public:
	void display() const override
	{
		std::cout << "Derived: DerivedContainer: ";
		for (const auto& element: MyContainer<T>::elements_)
		{
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	DerivedContainer<int> obj;
	obj.addElement(1);
	obj.addElement(2);
	obj.addElement(3);
	obj.display();

	MyContainer<int> obj_2;
	obj_2.addElement(31);
	obj_2.addElement(23);
	obj_2.addElement(54);
	obj_2.display();

	return 0;
}
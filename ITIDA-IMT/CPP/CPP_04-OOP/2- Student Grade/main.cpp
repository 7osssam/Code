#include "StudentClass.hpp"
#include <iostream>
#include <string>

void Student::display_info() const
{
	std::cout << "\tStudent details" << std::endl;
	std::cout << "Name: " << "\t\t" << name << std::endl;
	std::cout << "Class: " << "\t\t" << class_name << std::endl;
	std::cout << "Roll number: " << "\t" << roll_number << std::endl;
	std::cout << "Marks (0-100): " << "\t" << marks << std::endl;
	std::cout << "Grade: " << "\t\t" << calculate_grade() << std::endl;
}

int main()
{
	Student student;
	student.set_name("Hossam Mohmed");
	student.set_class_name("A");
	student.set_roll_number(3);
	student.set_marks(98);

	student.display_info();
	return 0;
}
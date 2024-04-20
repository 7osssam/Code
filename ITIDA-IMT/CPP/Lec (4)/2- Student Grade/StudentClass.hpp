// guard
#ifndef STUDENTCLASS_HPP
#define STUDENTCLASS_HPP

#include <string>

class Student
{
private:
	std::string name;
	std::string class_name;
	int			roll_number;
	int			marks;

public:
	// Default constructor
	Student(std::string name = "", std::string class_name = "", int roll_number = 0, int marks = 0) :
		name(name), class_name(class_name), roll_number(roll_number), marks(marks)
	{
	}

	// Setter for name
	void set_name(std::string new_name)
	{
		name = new_name;
	}

	// Getter for name
	std::string get_name() const
	{
		return name;
	}

	// Setter for class name
	void set_class_name(std::string new_class_name)
	{
		class_name = new_class_name;
	}

	// Getter for class name
	std::string get_class_name() const
	{
		return class_name;
	}

	// Setter for roll number
	void set_roll_number(int new_roll_number)
	{
		roll_number = new_roll_number;
	}

	// Getter for roll number
	int get_roll_number() const
	{
		return roll_number;
	}

	// Setter for marks
	void set_marks(int new_marks)
	{
		marks = new_marks;
	}

	// Function to calculate the grade
	char calculate_grade() const
	{
		if (marks >= 90)
			return 'A';
		else if (marks >= 80)
			return 'B';
		else if (marks >= 70)
			return 'C';
		else if (marks >= 60)
			return 'D';
		else
			return 'F';
	}

	// Function to display the student's information
	void display_info() const;
};

#endif // STUDENTCLASS_HPP
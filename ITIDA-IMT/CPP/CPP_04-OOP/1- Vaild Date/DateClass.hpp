// guard
#ifndef DATECLASS_HPP
#define DATECLASS_HPP

class Date
{
private:
	int day;
	int month;
	int year;

public:
	// Default constructor
	Date(int day = 0, int month = 0, int year = 0) : day(day), month(month), year(year)
	{
	}

	// Setter for day
	void set_day(int new_day)
	{
		day = new_day;
	}

	// Getter for day
	int get_day() const
	{
		return day;
	}

	// Setter for month
	void set_month(int new_month)
	{
		month = new_month;
	}

	// Getter for month
	int get_month() const
	{
		return month;
	}

	// Setter for year
	void set_year(int new_year)
	{
		year = new_year;
	}

	// Getter for year
	int get_year() const
	{
		return year;
	}

	// Function to validate the date
	bool is_valid() const
	{
		// Basic validation
		if (year < 0)
			return false;
		if (month < 1 || month > 12)
			return false;
		if (day < 1 || day > 31)
			return false;

		// Check for months with 30 days
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			return false;

		// Check for February and leap year
		if (month == 2)
		{
			bool is_leap = false;
			if (year % 4 == 0)
			{
				if (year % 100 == 0)
				{
					if (year % 400 == 0)
					{
						is_leap = true;
					}
				}
				else
				{
					is_leap = true;
				}
			}

			if (day > 29 || (day == 29 && !is_leap))
				return false;
		}

		return true;
	}
};

#endif // DATECLASS_HPP
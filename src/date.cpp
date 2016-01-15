#include "date.h"


//------------------------------------------------------------------------------
// Constructor
Date::Date()
{
	_month = 0;
	_year = 0;
}

//------------------------------------------------------------------------------
// Destructor
Date::~Date()
{
}

//------------------------------------------------------------------------------
// Date(month, year)
// creates a date setting information through passed in parameter
// month, year
Date::Date(const int month, const int year)
{
	_month = 0;
	_year = 0;
	if (month > 0 && month < 13)
	{
		_month = month;
	}
	if (year > 0 && year < 10000)
	{
		_year = year;
	}
}

//------------------------------------------------------------------------------
// Date(year)
// sets date year
Date::Date(const int year)
{
	_month = 0;
	_year = 0;
	if (year > 0 && year < 10000)
	{
		_year = year;
	}
}

//------------------------------------------------------------------------------
// getMonth
// returns month
int Date::getMonth() const
{
	return _month;
}

//------------------------------------------------------------------------------
// getYear
// returns year
int Date::getYear() const
{
	return _year;
}

//------------------------------------------------------------------------------
// operator==
bool Date::operator==(const Date &rhs) const
{
	return _month == rhs._month &&
		_year == rhs._year;
}

//------------------------------------------------------------------------------
// operator!=
bool Date::operator!=(const Date &rhs) const
{
	return _month != rhs._month ||
		_year != rhs._year;
}

//------------------------------------------------------------------------------
// operator>
bool Date::operator>(const Date &rhs) const
{
	if (_year != rhs._year)
	{
		return _year > rhs._year;
	}
	else
	{
		return _month > rhs._month;
	}
}

//------------------------------------------------------------------------------
// operator<
bool Date::operator<(const Date &rhs) const
{
	if (_year != rhs._year)
	{
		return _year < rhs._year;
	}
	else
	{
		return _month < rhs._month;

	}
}

//------------------------------------------------------------------------------
// operator>=
bool Date::operator>=(const Date &rhs) const
{
	if (_year != rhs._year)
	{
		return _year > rhs._year;
	}
	else
	{
		if (_month != rhs._month)
		{
			return _month > rhs._month;
		}
		else
		{
			return true;
		}
	}
}

//------------------------------------------------------------------------------
// operator<=
bool Date::operator<=(const Date &rhs) const
{
	if (_year != rhs._year)
	{
		return _year < rhs._year;
	}
	else
	{
		if (_month != rhs._month)
		{
			return _month < rhs._month;
		}
		else
		{
			return true;
		}
	}
}
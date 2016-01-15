#pragma once

// -----------------------------------------------------------------------------
// Date class: object that represents a date
//  -- Any data field set to zero presents no date for that field
//  -- has a month
//  -- has a year
//  -- zero represent no field

class Date
{
public:
	Date();
	// month, year
	Date(const int, const int);
	// year
	Date(const int);
	~Date();
	// returns month
	int getMonth() const;
	// returns year
	int getYear() const;

	// operator overloads
	bool operator==(const Date &) const;
	bool operator!=(const Date &) const;
	bool operator>(const Date &) const;
	bool operator<(const Date &) const;
	bool operator>=(const Date &) const;
	bool operator<=(const Date &) const;


private:
	// month
	int _month;
	// year
	int _year;
};


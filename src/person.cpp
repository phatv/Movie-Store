#include "person.h"

//------------------------------------------------------------------------------
// Constructor
Person::Person()
{
	_first = "";
	_last = "";
}

//------------------------------------------------------------------------------
// Destructor
Person::~Person()
{
}

//------------------------------------------------------------------------------
// Person(string, string)
// creates a person, setting their name from parameter
// first name, last name
Person::Person(string first, string last)
{
	_first = first;
	_last = last;
}

//------------------------------------------------------------------------------
// getFirst
// return person's first name
string Person::getFirst() const
{
	return _first;
}

//------------------------------------------------------------------------------
// getLast
// returns person's last name
string Person::getLast() const
{
	return _last;
}

//------------------------------------------------------------------------------
// operator==
bool Person::operator==(const Person &rhs) const
{
	return _first == rhs._first && _last == rhs._last;
}

//------------------------------------------------------------------------------
// operator!=
bool Person::operator!=(const Person &rhs) const
{
	return _first != rhs._first || _last != rhs._last;
}

//------------------------------------------------------------------------------
// operator<
bool Person::operator<(const Person &rhs) const
{
	if (_last != rhs._last)
	{
		return _last < rhs._last;
	}
	else
	{
		return _first < rhs._first;
	}
}

//------------------------------------------------------------------------------
// operator>
bool Person::operator>(const Person &rhs) const
{
	if (_last != rhs._last)
	{
		return _last > rhs._last;
	}
	else
	{
		return _first > rhs._first;
	}
}

//------------------------------------------------------------------------------
// operator<=
bool Person::operator<=(const Person &rhs) const
{
	if (_last != rhs._last)
	{
		return _last < rhs._last;
	}
	else
	{
		if (_first != rhs._first)
		{
			return _first < rhs._first;
		}
		else
		{
			return true;
		}
	}
}

//------------------------------------------------------------------------------
// operator>=
bool Person::operator>=(const Person &rhs) const
{
	if (_last != rhs._last)
	{
		return _last > rhs._last;
	}
	else
	{
		if (_first != rhs._first)
		{
			return _first > rhs._first;
		}
		else
		{
			return true;
		}
	}
}
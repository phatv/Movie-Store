#pragma once
#include <string>
using namespace std;

// -----------------------------------------------------------------------------
// Person class: object that represents a person
//  -- has a first name
//  -- has a last name

class Person
{
public:
	Person();
	// first name, last name
	Person(const string, const string);
	virtual ~Person();

	// return person's first name
	string getFirst() const;
	// returns person's last name
	string getLast() const;

	// operator overloads
	virtual bool operator==(const Person &) const;
	virtual bool operator!=(const Person &) const;
	virtual bool operator<(const Person &) const;
	virtual bool operator>(const Person &) const;
	virtual bool operator<=(const Person &) const;
	virtual bool operator>=(const Person &) const;

protected:
	// first name
	string _first;
	// last name
	string _last;
};


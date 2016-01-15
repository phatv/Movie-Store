#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

// -----------------------------------------------------------------------------
// Item class: represents all items in the store
//  -- must have hash function so it can be stored in hash
//  -- must have print function to retrieve data

class Item
{
	friend ostream& operator<<(ostream&, const Item &);
public:
	Item();
	virtual ~Item();

	// abstract hash function
	// used to sorting in hash table
	virtual int hash() const = 0;
	// prints item's name
	virtual void print(ostream &) const = 0;

	// operator overloads
	virtual bool operator==(const Item &) const = 0;
	virtual bool operator!=(const Item &) const = 0;
	virtual bool operator<(const Item &) const = 0;
	virtual bool operator>(const Item &) const = 0;
	virtual bool operator<=(const Item &) const = 0;
	virtual bool operator>=(const Item &) const = 0;
};


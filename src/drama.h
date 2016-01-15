#pragma once
#include "movie.h"

// -----------------------------------------------------------------------------
// Drama class: derived class of Movie

class Drama : public Movie
{
public:
	Drama();
	~Drama();
	// director, title, release date
	Drama(Person, string, Date);

	// return clone of drama
	Drama* clone() const;
	// returns new drama
	Drama* create() const;
	// sets data for a drama movie
	// director, title, release date
	bool setData(istream &);
	// sets just the sorting data
	// director then title
	void setSortData(istream &);
	// returns a unique hash for dramas
	int hash() const;
	// prints out movie information
	void print(ostream &) const;

	// operator overloads
	bool operator==(const Item &) const;
	bool operator!=(const Item &) const;
	bool operator<(const Item &) const;
	bool operator>(const Item &) const;
	bool operator<=(const Item &) const;
	bool operator>=(const Item &) const;
};


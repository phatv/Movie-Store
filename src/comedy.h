#pragma once
#include "movie.h"

// -----------------------------------------------------------------------------
// Comedy class: derived class of movie

class Comedy : public Movie
{
public:
	Comedy();
	~Comedy();
	// director, title, release date
	Comedy(Person, string, Date);

	// returns a copy of the movie
	Comedy* clone() const;
	// returns a new comedy
	Comedy* create() const;
	// sets data from file
	// directory, title, release date
	bool setData(istream &);
	// sets just sorting date
	// title, date
	void setSortData(istream &);
	// returns unique hashing id
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


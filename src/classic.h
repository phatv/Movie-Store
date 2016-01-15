#pragma once
#include "movie.h"

// -----------------------------------------------------------------------------
// Classic class: Derived class of Movie
//  -- has a star actor

class Classic : public Movie
{
public:
	Classic();
	~Classic();
	// director, title, actor, release date
	Classic(Person, string, Person, Date);

	// returns star actor
	Person getActor() const;
	// creates a copy of this movie
	Classic* clone() const;
	// returns new classic movie
	Classic* create() const;
	// sets date from istream
	// director, title, actor, release date
	bool setData(istream &);
	// sets just the sorting criteria
	// actor, release date
	void setSortData(istream &);
	// returns a unique hash number
	int hash() const;
	// displays movie information
	void print(ostream &) const;

	// operator overloads
	bool operator==(const Item &) const;
	bool operator!=(const Item &) const;
	bool operator<(const Item &) const;
	bool operator>(const Item &) const;
	bool operator<=(const Item &) const;
	bool operator>=(const Item &) const;

private:
	// star actor
	Person _actor;
};
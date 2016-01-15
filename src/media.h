#pragma once
#include "item.h"
#include "date.h"
#include "format.h"
#include "person.h"
#include <string>
#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// Media class: child class of items, parent class of inventory items related 
//   to digital entertainment
//  -- has a Title
//  -- has a release date
//  -- has a format
//  -- accessors and mutators for each of it's data fields

static const int OUTPUT_MAX_LENGTH_TITLE = 21;

class Media : public Item
{
public:
	Media();
	virtual ~Media();

	// returns title of movie
	string getTitle() const;
	// returns date of release
	Date getReleaseDate() const;
	// returns format
	// (this is where the quantity of the item is stored)
	Format* getFormat() const;
	// sets format for a movie
	// does nothing if movie already has a format
	void addFormat(Format *);

	// operator overload
	void operator=(const Media &);

protected:
	// title of the movie
	string _title;
	// date of movie's release
	Date _releaseDate;
	// format ex. DVD
	// this is where the quantity of the item is stored
	Format *_format;
};
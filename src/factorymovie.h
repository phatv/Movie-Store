#pragma once
#include "movie.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"

// -----------------------------------------------------------------------------
// Factory class: creates movie based on a given char
//  -- creates the appropiate object from a given char
//  -- char is encoded through a hash
//  -- has a factory array that creates the action

static const int FACTORY_M_SIZE = 6;

class FactoryMovie
{
public:
	FactoryMovie();
	~FactoryMovie();

	// returns a new movie from char parameter
	Movie* createIt(const char &) const;

private:
	// array of child movies
	Movie *_factory[FACTORY_M_SIZE];
	// hash function char to int
	int hash(const char &) const;
};


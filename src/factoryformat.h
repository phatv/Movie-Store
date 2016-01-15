#pragma once
#include "format.h"
#include "dvd.h"

// -----------------------------------------------------------------------------
// Factory class: creates format based on a given char
//  -- creates the appropiate object from a given char
//  -- char is encoded through a hash
//  -- has a factory array that creates the action

static const int FACTORY_F_SIZE = 4;

class FactoryFormat
{
public:
	FactoryFormat();
	~FactoryFormat();

	// creates a new format
	Format* createIt(const char &) const;

private:
	// array of formats
	Format *_factory[FACTORY_F_SIZE];
	// hash function turning char into int
	int hash(const char &) const;
};


#include "dvd.h"

//------------------------------------------------------------------------------
// Constructor
DVD::DVD()
{
	_type = "DVD";
	_quantity = 0;
	_inStock = 0;
}

//------------------------------------------------------------------------------
// Destructor
DVD::~DVD()
{
}

//------------------------------------------------------------------------------
// DVD(int)
// creates a new dvd, setting the format to passed in int
DVD::DVD(const int amount)
{
	_type = "DVD";
	_quantity = amount;
	_inStock = amount;
}

//------------------------------------------------------------------------------
// create
// return new DVD
Format* DVD::create() const
{
	return new DVD;
}
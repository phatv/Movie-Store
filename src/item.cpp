#include "item.h"


//------------------------------------------------------------------------------
// Constructor
Item::Item()
{
}


//------------------------------------------------------------------------------
// Destructor
Item::~Item()
{
}

//------------------------------------------------------------------------------
// operator<<
// prints out item's information
ostream& operator<<(ostream &outstream, const Item &item)
{
	item.print(outstream);
	return outstream;
}
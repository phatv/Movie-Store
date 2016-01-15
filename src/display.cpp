#include "display.h"
#include "manager.h"


//------------------------------------------------------------------------------
// Constructor
Display::Display()
{
}

//------------------------------------------------------------------------------
// Destructor
Display::~Display()
{
}

//------------------------------------------------------------------------------
// execute
// displays entire inventory of manager
// calls manager's dispayinven function
bool Display::execute()
{
	_manager->displayInven();
	delete this;
	return true;
}

//------------------------------------------------------------------------------
// create
// returns new display action
Action* Display::create() const
{
	return new Display;
}

//------------------------------------------------------------------------------
// setData
// sets manager class to be used
bool Display::setData(Manager *manager, istream &infile)
{
	_manager = manager;
	return true;
}

//------------------------------------------------------------------------------
// print
// prints out "display"
void Display::print(ostream &outStream) const
{
	outStream << "Display" << endl;
}
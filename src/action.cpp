#include "action.h"

//------------------------------------------------------------------------------
// Constructor
Action::Action()
{
}

//------------------------------------------------------------------------------
// Destructor
Action::~Action()
{
}

//------------------------------------------------------------------------------
// execute
// executes the child action's function
bool Action::execute()
{
	return false;
}

//------------------------------------------------------------------------------
// operator<<
// prints out action information
ostream& operator<<(ostream &outstream, const Action &action)
{
	action.print(outstream);
	return outstream;
}
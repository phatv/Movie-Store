#include "history.h"
#include "manager.h"


//------------------------------------------------------------------------------
// Constructor
History::History()
{
}


//------------------------------------------------------------------------------
// Destructor
History::~History()
{
}

//------------------------------------------------------------------------------
// execute
// displays the history of a customer
bool History::execute()
{
	_customer = _manager->getCustomer(_id);
	if (_customer != NULL)
	{
		cout << "  *** Customer ID = " << _customer->getId()
			<< " " << _customer->getLast() << " " << _customer->getFirst() << endl;
		_customer->printHistory();
		cout << endl;
		delete this;
		return true;
	}
	else
	{
		delete this;
		return false;
	}
}

//------------------------------------------------------------------------------
// create
// returns a new history action
Action* History::create() const
{
	return new History;
}

//------------------------------------------------------------------------------
// setData
// sets the manager class and customer id
bool History::setData(Manager *manager, istream &infile)
{
	_manager = manager;
	infile >> _id;
	return true;
}

//------------------------------------------------------------------------------
// print
// prints out history was gotten
void History::print(ostream &outstream) const
{
	outstream << "got history";
}
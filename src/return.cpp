#include "return.h"
#include "manager.h"

//------------------------------------------------------------------------------
// Constructor
Return::Return()
{
}


//------------------------------------------------------------------------------
// Destructor
Return::~Return()
{
}

//------------------------------------------------------------------------------
// Return(customer, item)
// creates a return, setting data members to parameter
// customer, item
Return::Return(Customer *customer, Media *item)
{
	_customer = customer;
	_item = item;
}

//------------------------------------------------------------------------------
// execute
// returns an item to the inventory
// removes item from customer's checkedout list
bool Return::execute()
{
	// validates if customer has item checked out
	if (validate())
	{
		Movie *movie = static_cast<Movie*>(_item);
		// gets format of movie then adds one to current inventory
		if (_customer->search(movie))
		{
			// increment inventory stock
			if (_format->add())
			{
				_customer->ret(movie);
				_customer->addHistory(this);
				return true;
			}
			else
			{
				cerr << "Too much stock" << movie->getTitle() << endl;
				return false;
			}
		}
		else
		{
			cerr << "Customer " << _customer->getFirst() + " " + _customer->getLast()
				<< " " << "has not checked out " << movie->getTitle() << endl;
			return false;
		}
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------------------------------
// create
// return new return action
Action* Return::create() const
{
	return new Return;
}

//------------------------------------------------------------------------------
// print
// prints out return information and item information
void Return::print(ostream &outstream) const
{
	// print out format type (DVD in this case)
	outstream << _format->getType() << " ";
	// print out action name
	outstream << "Return  ";
	// print out title of item
	outstream << *_item;
}
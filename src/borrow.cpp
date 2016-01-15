#include "borrow.h"
#include "manager.h"

//------------------------------------------------------------------------------
// Constructor
Borrow::Borrow()
{
}


//------------------------------------------------------------------------------
// Destructor
Borrow::~Borrow()
{
}

//------------------------------------------------------------------------------
// Borrow
// creates a new borrow, passing in information through parameter
// customer, item
Borrow::Borrow(Customer *customer, Media *item)
{
	_customer = customer;
	_item = item;
}

//------------------------------------------------------------------------------
// execute
// borrows an item from the inventory
// subtracts item and adds it to customer's checkedout list
bool Borrow::execute()
{
	if (validate())
	{
		Movie *movie = static_cast<Movie*>(_item);
		// gets format of movie then subtracts one from current inventory
		if (_format->sub())
		{
			_customer->bor(movie);
			_customer->addHistory(this);
			return true;
		}
		else
		{
			cerr << "Out of stock: " << _item->getTitle() << endl;
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
// return new borrow action
Action* Borrow::create() const
{
	return new Borrow;
}

//------------------------------------------------------------------------------
// print
// prints out borrow action information: item
void Borrow::print(ostream &outstream) const
{
	// print out format type (DVD in this case)
	outstream << _item->getFormat()->getType() << " ";
	// print out action name
	outstream << "Borrow  ";
	// print out title of item
	outstream << *_item;
}
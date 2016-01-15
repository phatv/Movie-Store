#include "customer.h"


//------------------------------------------------------------------------------
// Constructor
Customer::Customer()
{
	_first = "";
	_last = "";
	_id = -1;
}

//------------------------------------------------------------------------------
// Destructor
Customer::~Customer()
{
}

//------------------------------------------------------------------------------
// Customer
// sets data of customer through parameters
// first name, last name, id number
Customer::Customer(string first, string last, int id)
{
	_first = first;
	_last = last;
	_id = id;
}

//------------------------------------------------------------------------------
// Customer(person)
// sets data of customer through parameter
// person, id number
Customer::Customer(Person cust, int id)
{
	_first = cust.getFirst();
	_last = cust.getLast();
	_id = id;
}

//------------------------------------------------------------------------------
// getId
// returns id number
int Customer::getId() const
{
	return _id;
}

//------------------------------------------------------------------------------
// addHistory
// adds an action to customer's history list
void Customer::addHistory(Action *action)
{
	_history.append(action);
}

//------------------------------------------------------------------------------
// printHistory
// prints out list of customer's action history
void Customer::printHistory() const
{
	_history.print();
}

//------------------------------------------------------------------------------
// bor
// customer borrows a movie
// adds movie to customer's checkedout list
bool Customer::bor(Movie *movie)
{
	return _outMovies.append(movie);
}

//------------------------------------------------------------------------------
// ret
// customer returns a movie
// subtracts movie from a customer's checkedout list
bool Customer::ret(Movie *movie)
{
	return _outMovies.remove(movie);
}

//------------------------------------------------------------------------------
// search
// searches through customer's checkedout list for given movie
bool Customer::search(Movie *movie) const
{
	return _outMovies.search(movie);
}

//------------------------------------------------------------------------------
// operator==
// equals if two customer id are the same
bool Customer::operator==(const Customer &rhs) const
{
	return _id == rhs._id;
}

//------------------------------------------------------------------------------
// operator!=
// not equal if two customer id are different
bool Customer::operator!=(const Customer &rhs) const
{
	return _id != rhs._id;
}
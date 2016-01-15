#include "transaction.h"
#include "manager.h"

//------------------------------------------------------------------------------
// Constructor
Transaction::Transaction()
{
}


//------------------------------------------------------------------------------
// Destructor
Transaction::~Transaction()
{
}

//------------------------------------------------------------------------------
// getCustomer
// returns customer being handled
Customer* Transaction::getCustomer() const
{
	return _customer;
}

//------------------------------------------------------------------------------
// getMedia
// returns media item being handled
Media* Transaction::getMedia() const
{
	return _item;
}

//------------------------------------------------------------------------------
// setData
// sets data for a transaction
// manager, reads data from infile
// creates a new movie to be handled and compared to
// sets customer id, format, and genre
bool Transaction::setData(Manager *manager, istream &infile)
{
	_manager = manager;
	// sets id, format, genre
	infile >> _id >> _cFormat >> _genre;
	// creates a movie
	Movie *movie = _factoryMovie.createIt(_genre);
	// sets movie's data so it can be searched
	if (movie != NULL)
	{
		Format *format = _factoryFormat.createIt(_cFormat);
		if (format != NULL)
		{
			movie->setSortData(infile);
			movie->addFormat(format);
			_item = movie;
			return true;
		}
		else
		{
			cerr << "Invalid Format Code: " << _cFormat << endl;
			delete movie;
			movie = NULL;
		}
	}
	else
	{
		cerr << "Invalid Movie Genre: " << _genre << endl;
	}
	string s;
	getline(infile, s);
	return false;
}

//------------------------------------------------------------------------------
// validate
// checks if customer exist in database, movie exist in inventory
// returns true if both are
bool Transaction::validate()
{
	// looks for customer
	_customer = _manager->getCustomer(_id);
	if (_customer == NULL)
	{
		if (_item != NULL)
		{
			delete _item;
			_item = NULL;
		}
		cerr << "Customer not found: " << _id << endl;
		return false;
	}
	// looks for item
	Item *temp = _manager->getItem(_item);
	if (temp == NULL)
	{
		cerr << "Item not found: ";
		if (_item != NULL)
		{
			cerr << _item->getTitle();
			delete _item;
			_item = NULL;
		}
		cerr << endl;
		return false;
	}

	Movie *movie = static_cast<Movie*>(temp);
	// checks if format are the same
	if (_item->getFormat()->getType() != movie->getFormat()->getType())
	{
		cerr << "Format " << movie->getFormat()->getType() << " not in stock" << endl;
		delete _item;
		_item = NULL;
		return false;
	}
	// deletes old item, replaces with pointer to item in database
	delete _item;
	_item = movie;
	_format = _item->getFormat();
	return true;
}
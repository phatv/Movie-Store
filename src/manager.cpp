#include "manager.h"
#include "action.h"

//------------------------------------------------------------------------------
// Constructor
Manager::Manager()
{
}


//------------------------------------------------------------------------------
// Destructor
Manager::~Manager()
{
}

//------------------------------------------------------------------------------
// buildMovies
// build movie data through data file of movies
// creates movie from a factory, sets data passing infile
// adds movie to inventory
void Manager::buildMovies(istream &infile)
{
	if (!infile)
	{
		cerr << "File could not be opened." << endl;
		return;
	}

	char genre;
	Movie *movie;
	while (!infile.eof())
	{
		// retrieves movie genre to be created
		infile >> genre;
		movie = _factoryMovie.createIt(genre);
		if (movie != NULL)
		{
			// sets movie data
			if (movie->setData(infile))
			{
				movie->addFormat(new DVD(NUM_OF_DVD));
				//_inventory.addMovie(movie);
				if (!_inventory.add(genre, movie))
				{
					delete movie;
				}
			}
			else
			{
				delete movie;
			}
			movie = NULL;
		}
		else
		{
			// error if genre is not supported
			cerr << "Invalid Movie Code: " << genre << endl;
			string s;
			getline(infile, s);
		}
	}
}

//------------------------------------------------------------------------------
// buildCustomers
// build customer database from file
// adds customers to a customer hash
void Manager::buildCustomers(istream &infile)
{
	if (!infile)
	{
		cerr << "File could not be opened." << endl;
		return;
	}

	Customer *customer;
	int id;
	string first, last;
	while (!infile.eof())
	{
		// sets customer data
		infile >> id >> last >> first;
		customer = new Customer(first, last, id);
		_database.add(customer);
		customer = NULL;
	}
}

//------------------------------------------------------------------------------
// read
// reads commands from a file
// creates a command and stores it in a queue to be executed later
void Manager::read(istream &infile)
{
	if (!infile)
	{
		cerr << "File could not be opened." << endl;
		return;
	}

	char type;
	Action *action = NULL;
	while (!infile.eof())
	{
		// creates the action
		infile >> type;
		action = _factoryAction.createIt(type);
		if (action != NULL)
		{
			// sets action data
			if (action->setData(this, infile))
			{
				_task.push(action);
				action = NULL;
			}
			else
			{
				delete action;
				action = NULL;
			}
		}
		else
		{
			cerr << "Invalid Action Code: " << type << endl;
			string s;
			getline(infile, s);
		}
	}
}

//------------------------------------------------------------------------------
// run
// traverses through action queue executing each command
// actions are stored within customer after execution
void Manager::run()
{
	Action *action = NULL;
	while (!_task.empty())
	{
		action = _task.front();
		if (!action->execute())
		{
			delete action;
		}
		_task.pop();
	}
}

//------------------------------------------------------------------------------
// getCustomer
// retrieves and returns customer
// NULL if not found
Customer* Manager::getCustomer(const int &id)
{
	return _database.get(id);
}

//------------------------------------------------------------------------------
// getItem
// retrieves and returns item
// NULL if not found
Item* Manager::getItem(const Item *item)
{
	return _inventory.getItem(item);
}

//------------------------------------------------------------------------------
// displayInven
// prints out current inventory along with stock
void Manager::displayInven()
{
	_inventory.display();
}
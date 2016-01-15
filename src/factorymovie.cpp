#include "factorymovie.h"


//------------------------------------------------------------------------------
// Constructor
// sets array to new factory child classes
// index are based on child movie's char hash
FactoryMovie::FactoryMovie()
{
	for (int i = 0; i < FACTORY_M_SIZE; i++)
	{
		_factory[i] = NULL;
	}
	_factory[2] = new Classic;
	_factory[3] = new Drama;
	_factory[5] = new Comedy;
}

//------------------------------------------------------------------------------
// Destructor
FactoryMovie::~FactoryMovie()
{
	for (int i = 0; i < FACTORY_M_SIZE; i++)
	{
		if (_factory[i] != NULL)
		{
			delete _factory[i];
			_factory[i] = NULL;
		}
	}
}

//------------------------------------------------------------------------------
// createIt
// returns one of movie's child classes
// based on passed in char
Movie* FactoryMovie::createIt(const char &c) const
{
	int sub = hash(c);
	if (sub >= 0 && sub < FACTORY_M_SIZE)
	{
		Movie *movie = _factory[sub];
		if (movie != NULL)
		{
			return movie->create();
		}
	}
	return NULL;
}

//------------------------------------------------------------------------------
// hash
// hashes char into an int
int FactoryMovie::hash(const char &c) const
{
	return c - 'A';
}
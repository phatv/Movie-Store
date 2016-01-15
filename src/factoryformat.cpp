#include "factoryformat.h"


//------------------------------------------------------------------------------
// Constructor
// sets array to the cild classes for format
FactoryFormat::FactoryFormat()
{
	for (int i = 0; i < FACTORY_F_SIZE; i++)
	{
		_factory[i] = NULL;
	}
	_factory[3] = new DVD;
}


//------------------------------------------------------------------------------
// Destructor
FactoryFormat::~FactoryFormat()
{
	for (int i = 0; i < FACTORY_F_SIZE; i++)
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
// returns a new format from the passed in char
Format* FactoryFormat::createIt(const char &c) const
{
	int sub = hash(c);
	if (sub >= 0 && sub < FACTORY_F_SIZE)
	{
		Format *format = _factory[sub];
		if (format != NULL)
		{
			return format->create();
		}
	}
	return NULL;
}

//------------------------------------------------------------------------------
// hash
// hashes a char to an int
int FactoryFormat::hash(const char &c) const
{
	return c - 'A';
}
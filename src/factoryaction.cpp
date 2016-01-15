#include "factoryaction.h"


//------------------------------------------------------------------------------
// Constructor
// sets array of factory to each of factory's child classes
// index are based on hash char
FactoryAction::FactoryAction()
{
	for (int i = 0; i < FACTORY_A_SIZE; i++)
	{
		_factory[i] = NULL;
	}
	_factory[1] = new Borrow;
	_factory[17] = new Return;
	_factory[7] = new History;
	_factory[18] = new Display;
}


//------------------------------------------------------------------------------
// Destructor
FactoryAction::~FactoryAction()
{
	for (int i = 0; i < FACTORY_A_SIZE; i++)
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
// creates new action based on the passed in char
// returns a child of action
Action* FactoryAction::createIt(const char &c) const
{
	int sub = hash(c);
	if (sub >= 0 && sub < FACTORY_A_SIZE)
	{
		Action *action = _factory[sub];
		if (action != NULL)
		{
			return action->create();
		}
	}
	return NULL;
}

//------------------------------------------------------------------------------
// hash
// hashes a char into an int
int FactoryAction::hash(const char &c) const
{
	return c - 'A';
}
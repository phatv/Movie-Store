#include "hashitem.h"


//------------------------------------------------------------------------------
// Constructor
HashItem::HashItem()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		_table[i] = NULL;
	}
}


//------------------------------------------------------------------------------
// Destructor
HashItem::~HashItem()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		delete _table[i];
		_table[i] = NULL;
	}
}

//------------------------------------------------------------------------------
// add
// adds an item to the hash
// uses item's own hash function
bool HashItem::add(Item *item)
{
	int key = item->hash() % MAX_SIZE;
	// attempt = number of tries
	int attempt = 0;
	while (attempt < MAX_SIZE)
	{
		if (_table[key] == NULL)
		{
			_table[key] = item;
			return true;
		}
		else
		{
			attempt++;
			key = rehash(key, attempt);
		}
	}
	cerr << "Error: Hash table full" << endl;
	return false;
}

//------------------------------------------------------------------------------
// get
// retrieves an item from the hash
// uses item's own hash function
Item* HashItem::get(const Item *item) const
{
	if (item != NULL)
	{
		int key = item->hash() % MAX_SIZE;
		int attempt = 0;
		while (attempt < MAX_SIZE)
		{
			if (_table[key] != NULL)
			{
				if (*_table[key] == *item)
				{
					return _table[key];
				}
				else
				{
					attempt++;
					key = rehash(key, attempt);
				}
			}
			else
			{
				return NULL;
			}
		}
	}
	return NULL;
}

//------------------------------------------------------------------------------
// rehash
// quadratic probing if previous index was taken
int HashItem::rehash(const int &k, const int &i) const
{
	return (k + i * i) % MAX_SIZE;
}
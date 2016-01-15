#include "hashcustomer.h"


//------------------------------------------------------------------------------
// Constructor
HashCustomer::HashCustomer()
{
	for (int i = 0; i < MAX_CUST; i++)
	{
		_table[i] = NULL;
	}
}


//------------------------------------------------------------------------------
// Destructor
HashCustomer::~HashCustomer()
{
	for (int i = 0; i < MAX_CUST; i++)
	{
		delete _table[i];
		_table[i] = NULL;
	}
}

//------------------------------------------------------------------------------
// add
// adds a customer to the hash table
bool HashCustomer::add(Customer *customer)
{
	int id = customer->getId();
	int key = hash(id);
	// attempts keeps attempting to add customer to table until
	// attempts reaches table size, meaning table is full
	int attempt = 0;
	while (attempt < MAX_CUST)
	{
		if (_table[key] == NULL)
		{
			_table[key] = customer;
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
// retrieves customer from hash table
Customer* HashCustomer::get(const int &id) const
{
	int key = hash(id);
	// attemps to retrieve customer until attemps reaches table size
	// customer not found if it reaches null or attempt reaches table size
	int attempt = 0;
	while (attempt < MAX_CUST)
	{
		if (_table[key] != NULL)
		{
			if (_table[key]->getId() == id)
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
	return NULL;
}

//------------------------------------------------------------------------------
// hash
// hashes customer id into an unique int
int HashCustomer::hash(const int &i) const
{
	return ((i % 389) * (i % 547) % MAX_CUST);
}

//------------------------------------------------------------------------------
// rehash
// quadratic probing if previous hash was taken
int HashCustomer::rehash(const int &k, const int &i) const
{
	return (k + i * i) % MAX_CUST;
}
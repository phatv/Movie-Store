#include "inventory.h"


//------------------------------------------------------------------------------
// Constructor
Inventory::Inventory()
{
	setHeading('C', 
		"DVD  DVD TITLE                 DIRECTOR         YEAR MO  ACTOR");
	setHeading('D', "DVD  DVD TITLE                 DIRECTOR         YEAR");
	setHeading('F', "DVD  DVD TITLE                 DIRECTOR         YEAR");
}

//------------------------------------------------------------------------------
// Destructor
Inventory::~Inventory()
{
}

//------------------------------------------------------------------------------
// add
// adds an item into the inventory hash and sorted tree
bool Inventory::add(const char &code, Item *item)
{
	if (item != NULL)
	{
		// creates a node for the tree
		NodeItem *nm = new NodeItem(item);
		int key = hashcat(code);
		// inserts into hash if tree insertion was success
		if (_movieByCat[key].tree.insert(nm))
		{
			_itemHash.add(item);
			return true;
		}
		else
		{
			cerr << "Duplicate movie: " << item << endl;
			delete nm;
			return false;
		}
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------------------------------
// getItem
// retrieves and item from the hash
Item* Inventory::getItem(const Item *obj) const
{
	Item *item = _itemHash.get(obj);
	if (item != NULL)
	{
		return item;
	}
	else
	{
		return NULL;
	}
}

//------------------------------------------------------------------------------
// hashcat
// hashes char into an int
int Inventory::hashcat(const char &c) const
{
	return c - 'A';
}

//------------------------------------------------------------------------------
// setHeading
// sets the heading of a tree for display
// parameter char is the category to be set, string is the heading
void Inventory::setHeading(const char &c, const string &s)
{
	_movieByCat[hashcat(c)].heading = s;
}

//------------------------------------------------------------------------------
// display
// displays the contents of a tree, categorized
// uses heading if set
void Inventory::display()
{
	for (int i = 0; i < INVEN_CATEGORY; i++)
	{
		// display tree that are not empty
		if (!_movieByCat[i].tree.isEmpty())
		{
			cout << "*IN* *OUT*" << endl;
			cout << _movieByCat[i].heading << endl;

			// creates an array of the movies in the tree
			NodeData *movies[INVEN_MAX_SIZE];
			for (int j = 0; j < INVEN_MAX_SIZE; j++)
			{
				movies[j] = NULL;
			}
			_movieByCat[i].tree.bstreeToArray(movies);

			// for the array size, goes through and displays each movie
			for (int k = 0; movies[k] != NULL; k++)
			{
				NodeMovie *nm = static_cast<NodeMovie*>(movies[k]);
				int currStock = nm->getMovie()->getFormat()->getCurrStock();
				int quantity = nm->getMovie()->getFormat()->getQuantity();
				int out = quantity - currStock;
				cout << setw(2) << right << currStock << "   "
					<< setw(2) << right << out << "  "
					<< *nm->getMovie() << endl;
			}
			cout << endl;
		}
	}
}
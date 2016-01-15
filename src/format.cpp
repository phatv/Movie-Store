#include "format.h"


//------------------------------------------------------------------------------
// Constructor
Format::Format()
{
	_type = "";
	_quantity = 0;
	_inStock = 0;
}


//------------------------------------------------------------------------------
// Destructor
Format::~Format()
{
}

//------------------------------------------------------------------------------
// add
// adds one to current inventory stock
bool Format::add()
{
	if (_quantity > _inStock)
	{
		_inStock++;
		return true;
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------------------------------
// sub
// subtract one from current inventory stock
bool Format::sub()
{
	if (0 < _inStock)
	{
		_inStock--;
		return true;
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------------------------------
// getQuantity
// return quantity
int Format::getQuantity() const
{
	return _quantity;
}

//------------------------------------------------------------------------------
// getCurrStock
// return current inventory stock
int Format::getCurrStock() const
{
	return _inStock;
}

//------------------------------------------------------------------------------
// getType
// return format's type
string Format::getType() const
{
	return _type;
}

//------------------------------------------------------------------------------
// addQuantity
// adds an amount to total inventory stock
bool Format::addQuantity(const int amount)
{
	if (amount > 0)
	{
		_quantity += amount;
		_inStock += amount;
		return true;
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------------------------------
// subQuantity
// subtracts an amount from total inventory stock
bool Format::subQuantity(const int amount)
{
	if (amount > 0)
	{
		_quantity -= amount;
		_inStock -= amount;
		if (_quantity < 0)
		{
			_quantity = 0;
			_inStock = 0;
		}
		return true;
	}
	else
	{
		return false;
	}
}
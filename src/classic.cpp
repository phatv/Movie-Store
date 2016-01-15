#include "classic.h"


//------------------------------------------------------------------------------
// Constructor
Classic::Classic()
{
	_genre = 'C';
	_title = "";
	_releaseDate;
	_director;
	_actor;
	_format = NULL;
}

//------------------------------------------------------------------------------
// Detructor
Classic::~Classic()
{
}

//------------------------------------------------------------------------------
// Classic
// creates classic with provided information in parameter
// director, title, actor, releasedate
Classic::Classic(Person director, string title, Person actor, Date date)
{
	_genre = 'C';
	_director = director;
	_title = title;
	_actor = actor;
	_releaseDate = date;
	_format = NULL;
}

//------------------------------------------------------------------------------
// getActor
// returns star actor
Person Classic::getActor() const
{
	return _actor;
}

//------------------------------------------------------------------------------
// clone
// returns a copy of classic movie
// format for copy is left to NULL
Classic* Classic::clone() const
{
	Classic *c = new Classic(_director, _title, _actor, _releaseDate);
	return c;
}

//------------------------------------------------------------------------------
// create
// returns new classic movie
Classic* Classic::create() const
{
	return new Classic;
}

//------------------------------------------------------------------------------
// setData
// sets data from istream file
// sets movie data first from movie class
// actor, release date is filled in if successful
bool Classic::setData(istream &infile)
{
	if (setMovieData(infile))
	{
		// actor
		string first, last;
		infile >> first >> last;
		_actor = Person(first, last);

		// date
		int month, year;
		infile >> month >> year;
		if (year >= MOVIE_EARLIEST_DATE && year <= CURRENT_YEAR)
		{
			if (month != 0)
			{
				_releaseDate = Date(month, year);
				return true;
			}
			else
			{
				cerr << "Invalid Movie Month: " << month << endl;
				return false;
			}
		}
		else
		{
			// deletes movie if it is not within possible dates
			cerr << "Invalid Movie Year: " << year << endl;
			return false;
		}
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------------------------------
// setSortData
// sets just the sorting data for classic
// classic sorting data is release date, star actor
void Classic::setSortData(istream &infile)
{
	// date
	int month, year;
	infile >> month >> year;
	_releaseDate = Date(month, year);

	// actor
	string first, last;
	infile >> first >> last;
	_actor = Person(first, last);
}

//------------------------------------------------------------------------------
// hash
// returns unique hash number created from classic's sorting data
int Classic::hash() const
{
	int i = _releaseDate.getMonth();
	int j = _releaseDate.getYear();
	char k = _actor.getFirst()[0];
	char l = _actor.getLast()[0];
	return (i + k) * (j + l);
}

//------------------------------------------------------------------------------
// print
// prints out movie data including:
// title, director, release date, actor
void Classic::print(ostream &outstream) const
{
	// print title of movie
	outstream << setw(OUTPUT_MAX_LENGTH_TITLE) << left 
		<< _title.substr(0, OUTPUT_MAX_LENGTH_TITLE) << " "
		// print director first and last
		<< setw(OUTPUT_MAX_LENGTH_DIRECTOR) << left
		<< (_director.getFirst() + " " + 
		_director.getLast()).substr(0, OUTPUT_MAX_LENGTH_DIRECTOR) << " "
		// print date
		<< _releaseDate.getYear() << " "
		<< setw(2) << right
		<< _releaseDate.getMonth() << "  "
		// print actor
		<< (_actor.getFirst() + " " + _actor.getLast());
}

//------------------------------------------------------------------------------
// operator==
// compares two classic movies are equal
// equals if sorting data match
bool Classic::operator==(const Item &rhs) const
{
	const Classic &temp = static_cast<const Classic&>(rhs);
	return _genre == temp._genre &&
		_releaseDate == temp._releaseDate &&
		_actor == temp._actor;
}

//------------------------------------------------------------------------------
// operator!=
// compares two classic movies are not equal
// not equal if sorting data do not match
bool Classic::operator!=(const Item &rhs) const
{
	const Classic &temp = static_cast<const Classic&>(rhs);
	return _genre != temp._genre ||
		_releaseDate != temp._releaseDate ||
		_actor != temp._actor;
}

//------------------------------------------------------------------------------
// operator<
// compares two classic movies greater than
// compares classic movie's sorting data
bool Classic::operator<(const Item &rhs) const
{
	const Classic &temp = static_cast<const Classic&>(rhs);
	if (_releaseDate != temp._releaseDate)
	{
		return _releaseDate < temp._releaseDate;
	}
	else
	{
		return _actor < temp._actor;
	}
}

//------------------------------------------------------------------------------
// operator>
// compares classic movies less than 
// compares using classic movie sorting data
bool Classic::operator>(const Item &rhs) const
{
	const Classic &temp = static_cast<const Classic&>(rhs);
	if (_releaseDate != temp._releaseDate)
	{
		return _releaseDate > temp._releaseDate;
	}
	else
	{
		return _actor > temp._actor;
	}
}

//------------------------------------------------------------------------------
// operator<=
// compares if two classic movies are greater or equal
// compares using classic movie sorting data
bool Classic::operator<=(const Item &rhs) const
{
	const Classic &temp = static_cast<const Classic&>(rhs);
	if (_releaseDate != temp._releaseDate)
	{
		return _releaseDate < temp._releaseDate;
	}
	else
	{
		return _actor <= temp._actor;
	}
}

//------------------------------------------------------------------------------
// operator=>
// compares if two classic movies are less than or equal
// compares using classic movie sorting data
bool Classic::operator>=(const Item &rhs) const
{
	const Classic &temp = static_cast<const Classic&>(rhs);
	if (_releaseDate != temp._releaseDate)
	{
		return _releaseDate > temp._releaseDate;
	}
	else
	{
		return _actor >= temp._actor;
	}
}


#include "comedy.h"


//------------------------------------------------------------------------------
// Constructor
Comedy::Comedy()
{
	_genre = 'F';
	_director;
	_title;
	_releaseDate;
	_format = NULL;
}

//------------------------------------------------------------------------------
// Destructor
Comedy::~Comedy()
{
}

//------------------------------------------------------------------------------
// Comedy
// sets comedy data through info passed in parameter
// director, title, date
Comedy::Comedy(Person director, string title, Date date)
{
	_genre = 'F';
	_director = director;
	_title = title;
	_releaseDate = date;
	_format = NULL;
}

//------------------------------------------------------------------------------
// clone
// return copy of comedy movie
// format is set to NULL
Comedy* Comedy::clone() const
{
	Comedy *c = new Comedy(_director, _title, _releaseDate);
	return c;
}

//------------------------------------------------------------------------------
// create
// return new comedy movie
Comedy* Comedy::create() const
{
	return new Comedy;
}

//------------------------------------------------------------------------------
// setData
// sets data from istream file
// intial movie data is set through inheirited class from movie
// sets data for comedy movies
// release date
bool Comedy::setData(istream &infile)
{
	if (setMovieData(infile))
	{
		// sets date
		int year;
		infile >> year;
		if (year >= MOVIE_EARLIEST_DATE && year <= CURRENT_YEAR)
		{
			_releaseDate = Date(year);
			return true;
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
// sets sorting data for comedy through istream
// title, release date
void Comedy::setSortData(istream &infile)
{
	// sets title
	infile.get();
	getline(infile, _title, ',');
	infile.get();

	int year;
	infile >> year;
	_releaseDate = Date(year);
}

//------------------------------------------------------------------------------
// hash
// returns unique hashing int created from sorting data
int Comedy::hash() const
{
	char c = _title[0];
	int l = _title.length();
	int i = _releaseDate.getYear();
	return (i * l) + (c * c);

}

//------------------------------------------------------------------------------
// print
// prints out movie information
// title, director, release date
void Comedy::print(ostream &outstream) const
{
	// print title of movie
	outstream << setw(OUTPUT_MAX_LENGTH_TITLE) << left
		<< _title.substr(0, OUTPUT_MAX_LENGTH_TITLE) << " "
		// print director first and last
		<< setw(OUTPUT_MAX_LENGTH_DIRECTOR) << left
		<< (_director.getFirst() + " " +
		_director.getLast()).substr(0, OUTPUT_MAX_LENGTH_DIRECTOR) << " "
		// print date
		<< _releaseDate.getYear();
}

//------------------------------------------------------------------------------
// operator==
// compares two classic movies are equal
// equals if sorting data match
bool Comedy::operator==(const Item &rhs) const
{
	const Comedy &temp = static_cast<const Comedy&>(rhs);
	return _genre == temp._genre &&
		_title == temp._title &&
		_releaseDate == temp._releaseDate;
}

//------------------------------------------------------------------------------
// operator!=
// compares two classic movies are not equal
// not equal if sorting data do not match
bool Comedy::operator!=(const Item &rhs) const
{
	const Comedy &temp = static_cast<const Comedy&>(rhs);
	return _genre != temp._genre ||
		_title != temp._title ||
		_releaseDate != temp._releaseDate;
}

//------------------------------------------------------------------------------
// operator<
// compares two classic movies greater than
// compares classic movie's sorting data
bool Comedy::operator<(const Item &rhs) const
{
	const Comedy &temp = static_cast<const Comedy&>(rhs);
	if (_title != temp._title)
	{
		return _title < temp._title;
	}
	else
	{
		return _releaseDate < temp._releaseDate;
	}
}

//------------------------------------------------------------------------------
// operator>
// compares classic movies less than 
// compares using classic movie sorting data
bool Comedy::operator>(const Item &rhs) const
{
	const Comedy &temp = static_cast<const Comedy&>(rhs);
	if (_title != temp._title)
	{
		return _title > temp._title;
	}
	else
	{
		return _releaseDate > temp._releaseDate;
	}
}

//------------------------------------------------------------------------------
// operator<=
// compares if two classic movies are greater or equal
// compares using classic movie sorting data
bool Comedy::operator<=(const Item &rhs) const
{
	const Comedy &temp = static_cast<const Comedy&>(rhs);
	if (_title != temp._title)
	{
		return _title < temp._title;
	}
	else
	{
		return _releaseDate <= temp._releaseDate;
	}
}

//------------------------------------------------------------------------------
// operator=>
// compares if two classic movies are less than or equal
// compares using classic movie sorting data
bool Comedy::operator>=(const Item &rhs) const
{
	const Comedy &temp = static_cast<const Comedy&>(rhs);
	if (_title != temp._title)
	{
		return _title > temp._title;
	}
	else
	{
		return _releaseDate >= temp._releaseDate;
	}
}
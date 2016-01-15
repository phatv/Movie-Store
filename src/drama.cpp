#include "drama.h"


//------------------------------------------------------------------------------
// Constructor
Drama::Drama()
{
	_genre = 'D';
	_director;
	_title;
	_releaseDate;
	_format = NULL;
}

//------------------------------------------------------------------------------
// Destructor
Drama::~Drama()
{
}

//------------------------------------------------------------------------------
// Drama
// sets comedy data through info passed in parameter
// director, title, date
Drama::Drama(Person director, string title, Date date)
{
	_genre = 'D';
	_director = director;
	_title = title;
	_releaseDate = date;
	_format = NULL;
}

//------------------------------------------------------------------------------
// clone
// return copy of comedy movie
// format is set to NULL
Drama* Drama::clone() const
{
	Drama *c = new Drama(_director, _title, _releaseDate);
	return c;
}

//------------------------------------------------------------------------------
// create
// return new drama movie
Drama* Drama::create() const
{
	return new Drama;
}

//------------------------------------------------------------------------------
// setData
// sets data from istream file
// intial movie data is set through inheirited class from movie
// sets data for comedy movies
// release date
bool Drama::setData(istream &infile)
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
// director, title
void Drama::setSortData(istream &infile)
{
	// sets director
	string first, last;
	infile >> first;
	infile.get();
	getline(infile, last, ',');
	_director = Person(first, last);

	// sets title
	infile.get();
	getline(infile, _title, ',');
}

//------------------------------------------------------------------------------
// hash
// returns unique hashing int created from sorting data
int Drama::hash() const
{
	char i = _director.getFirst()[0];
	char j = _director.getLast()[0];
	char k = _title[0];
	int l = _title.length();
	return (i + k) * (j + l);
}

//------------------------------------------------------------------------------
// print
// prints out movie data including:
// title, director, release date
void Drama::print(ostream &outstream) const
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
bool Drama::operator==(const Item &rhs) const
{
	const Drama &temp = static_cast<const Drama&>(rhs);
	return _genre == temp._genre &&
		_title == temp._title &&
		_director == temp._director;
}

//------------------------------------------------------------------------------
// operator!=
// compares two classic movies are not equal
// not equal if sorting data do not match
bool Drama::operator!=(const Item &rhs) const
{
	const Drama &temp = static_cast<const Drama&>(rhs);
	return _genre != temp._genre ||
		_title != temp._title ||
		_director != temp._director;
}

//------------------------------------------------------------------------------
// operator<
// compares two classic movies greater than
// compares classic movie's sorting data
bool Drama::operator<(const Item &rhs) const
{
	const Drama &temp = static_cast<const Drama&>(rhs);
	if (_director != temp._director)
	{
		return _director.getFirst() < temp._director.getFirst();
	}
	else
	{
		return _title < temp._title;
	}
}

//------------------------------------------------------------------------------
// operator>
// compares classic movies less than 
// compares using classic movie sorting data
bool Drama::operator>(const Item &rhs) const
{
	const Drama &temp = static_cast<const Drama&>(rhs);
	if (_director != temp._director)
	{
		return _director.getFirst() > temp._director.getFirst();
	}
	else
	{
		return _title > temp._title;
	}
}

//------------------------------------------------------------------------------
// operator<=
// compares if two classic movies are greater or equal
// compares using classic movie sorting data
bool Drama::operator<=(const Item &rhs) const
{
	const Drama &temp = static_cast<const Drama&>(rhs);
	if (_director != temp._director)
	{
		return _director.getFirst() < temp._director.getFirst();
	}
	else
	{
		return _title <= temp._title;
	}
}

//------------------------------------------------------------------------------
// operator=>
// compares if two classic movies are less than or equal
// compares using classic movie sorting data
bool Drama::operator>=(const Item &rhs) const
{
	const Drama &temp = static_cast<const Drama&>(rhs);
	if (_director != temp._director)
	{
		return _director.getFirst() > temp._director.getFirst();
	}
	else
	{
		return _title >= temp._title;
	}
}
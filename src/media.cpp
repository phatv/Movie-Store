#include "media.h"


//------------------------------------------------------------------------------
// Constructor
Media::Media()
{
	_title = "";
	_releaseDate;
	_format = NULL;
}


//------------------------------------------------------------------------------
// Destructor
Media::~Media()
{
	delete _format;
	_format = NULL;
}

//------------------------------------------------------------------------------
// getTitle
// returns title
string Media::getTitle() const
{
	return _title;
}

//------------------------------------------------------------------------------
// getReleaseDate
// returns release date
Date Media::getReleaseDate() const
{
	return _releaseDate;
}

//------------------------------------------------------------------------------
// getFormat
// returns format
Format* Media::getFormat() const
{
	return _format;
}

//------------------------------------------------------------------------------
// addFormat
// if format is NULL, sets new format
// does nothing if format is not NULL
void Media::addFormat(Format *format)
{
	if (_format == NULL)
	{
		_format = format;
	}
}

//------------------------------------------------------------------------------
// operator=
// assignment operator
// copies title and release date
void Media::operator=(const Media &rhs)
{
	_title = rhs._title;
	_releaseDate = rhs._releaseDate;
}
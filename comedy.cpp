#include "comedy.h"

Comedy::Comedy(char type) {
	this->typeOfMovie = type;
}


Comedy::~Comedy()
{
}

bool Comedy::operator==(const Movie& other) const
{
	//compares the movie title, and release year to see if they are equal
	if (title == other.getTitle()) {
			if (director == other.getDirector()) {
				return true;
		}
	}
	//if any of those conditionals are broken
	return false;
}

bool Comedy::operator!=(const Movie& other) const
{
	return !(*this == other);
}

bool Comedy::operator>(const Movie& other) const
{

	//if titles aren't equal compare them
	//otherwise compare years
	if (title != other.getTitle()) {
		return title.compare(other.getTitle()) > 0;
	}
	return releaseYear > other.getReleaseYear();
}

bool Comedy::operator<(const Movie& other) const
{

	//if titles aren't equal compare them
	//otherwise compare years
	if (title != other.getTitle()) {
		return title.compare(other.getTitle()) < 0;
	}
	return releaseYear < other.getReleaseYear();
}


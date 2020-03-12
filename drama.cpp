#include "drama.h"

Drama::Drama(char type) {
	this->typeOfMovie = type;
}


Drama::~Drama()
{
}

bool Drama::operator==(const Movie& other) const
{
	//compares the director then movie title to see if they are equal
	if (director == other.getDirector()) {
		if (title == other.getTitle()) {
			return true;
		}
	}
	//if any of those conditionals are broken
	return false;
}

bool Drama::operator!=(const Movie& other) const
{
	return !(*this == other);
}

bool Drama::operator>(const Movie& other) const
{
//compare directors, if they're equal compare titles
	if (director != other.getDirector()) {
		return director.compare(other.getDirector()) > 0;
	}
		return title.compare(other.getTitle()) > 0;

}

bool Drama::operator<(const Movie& other) const
{
	//compare directors, if they're equal compare titles
	if (director != other.getDirector()) {
		return director.compare(other.getDirector()) < 0;
	}
	return title.compare(other.getTitle()) < 0;

}


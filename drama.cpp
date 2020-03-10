#include "drama.h"

Drama::Drama(int stock, string director, string title, int releaseYear) {
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->releaseYear = releaseYear;
}

Drama::~Drama()
{
}

bool Drama::operator==(const Drama& compared) const
{
	//compares the director then movie title to see if they are equal
	if (director == compared.getDirector()) {
		if (title == compared.getTitle()) {
			return true;
		}
	}
	//if any of those conditionals are broken
	return false;
}

bool Drama::operator!=(const Drama& compared) const
{
	return !(*this == compared);
}

bool Drama::operator>(const Drama& compared) const
{
//if this director is less than the compared movie's title
//and its less than the title we can return false
	if (director <= compared.getDirector()) {
		if (title <= compared.getTitle()) {
			return false;
		}
	}

	//otherwise the movie is greater than the compared movie
	return true;
}

bool Drama::operator<(const Drama& compared) const
{
	return !(*this > compared);
}

#include "classic.h"

Classic::Classic(int stock, string director, string title, string majorActor, int releaseMonth, int releaseYear)
{
	//MAYBE EDIT THIS@@@@@@@@@@@@@@@@@@@@@@@@@
	this->stock = stock;
	//MAYBE EDIT THIS@@@@@@@@@@@@@@@@@@@@@@@@@
	this->director = director;
	this->title = title;
	this->majorActor = majorActor;
	this->releaseMonth = releaseMonth;
	this->releaseYear = releaseYear;

}

Classic::Classic(const Classic& theMovie)
{
	*this = theMovie;
}

Classic::~Classic()
{
}

void Classic::setMajorActor(string actor)
{
	this->majorActor = actor;
}

void Classic::setReleaseMonth(int month)
{
	this->releaseMonth = month;
}

string Classic::getMajorActor() const
{
	return this->majorActor;
}

int Classic::getReleaseMonth() const
{
	return this->releaseMonth;
}

Classic Classic::operator=(const Classic& theMovie)
{
	stock = theMovie.getStock();
	director = theMovie.getDirector();
	title = theMovie.getTitle();
	majorActor = theMovie.getMajorActor();
	releaseMonth = theMovie.getReleaseMonth();
	releaseYear = theMovie.getReleaseYear();

	return *this;
}

bool Classic::operator==(const Classic& compared) const
{
	//compare the release date (first the year then the month)
	//and then compare the major actor to see if the two movies are equal
	if (releaseYear == compared.getReleaseYear()) {
		if (releaseMonth == compared.getReleaseMonth()) {
			if (majorActor == compared.getMajorActor()) {
				return true;
			}
		}
	}

	//if any conditional is broken we return false
	return false;
}

bool Classic::operator!=(const Classic& compared) const
{
	return !(*this == compared);
}

bool Classic::operator>(const Classic& compared) const
{
//if the release date is less than the other movie
//and major actor is less than the other major actor
//we can return false that this movie is not greater than the other movie
	if (releaseYear <= compared.getReleaseYear()) {
		if (releaseMonth <= compared.getReleaseMonth()) {
			if (majorActor <= compared.getMajorActor()) {
				return false;
			}
		}
	}

	//otherwise the movie is greater than the compared movie
	return true;
}

bool Classic::operator<(const Classic& compared) const
{
	return !(*this > compared);
}



#include "classic.h"

Classic::Classic(char type)
{
	this->typeOfMovie = type;
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


bool Classic::operator==(const Movie& other) const
{
	//compare the release date (first the year then the month)
	//and then compare the major actor to see if the two movies are equal
	if (releaseYear == other.getReleaseYear()) {
		if (releaseMonth == other.getReleaseMonth()) {
			if (majorActor == other.getMajorActor()) {
				return true;
			}
		}
	}

	//if any conditional is broken we return false
	return false;
}

bool Classic::operator!=(const Movie& other) const
{
	return !(*this == other);
}

bool Classic::operator>(const Movie& other) const
{
	if (releaseYear != other.getReleaseYear()) {
		return releaseYear > other.getReleaseYear();
}
	if (releaseMonth != other.getReleaseMonth()) {
		return releaseMonth > other.getReleaseMonth();
	}
	return majorActor.compare(other.getMajorActor()) > 0;
}

bool Classic::operator<(const Movie& other) const
{
	if (releaseYear != other.getReleaseYear()) {
		return releaseYear < other.getReleaseYear();
	}
	if (releaseMonth != other.getReleaseMonth()) {
		return releaseMonth < other.getReleaseMonth();
	}
	return majorActor.compare(other.getMajorActor()) < 0;
}

void Classic::display()
{

	cout << this->getTypeOfMovie() << ", " << this->getStock() << ", ";
	cout << this->getDirector() << ", " << this->getTitle() << ", ";
	cout << this->getMajorActor() << " " << this->getReleaseMonth() << " ";
	cout << this->getReleaseYear() << endl;
}



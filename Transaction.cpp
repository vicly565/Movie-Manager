#include "Transaction.h"

Transaction::~Transaction()
{
}


void Transaction::setTransactionType(char transtype)
{
	transactionType = transtype;
}

void Transaction::setCustomerID(int custID)
{
	customerId = custID;
}

void Transaction::setMediaType(char mediatype)
{
	mediaType = mediatype;
}

void Transaction::setMovieType(char filmtype)
{
	movieType = filmtype;
}

void Transaction::setTitle(string title)
{
	this->title = title;
}

void Transaction::setDirector(string director)
{
	this->director = director;
}

void Transaction::setReleaseMonth(int month)
{
	releaseMonth = month;
}

void Transaction::setReleaseYear(int year)
{
	releaseYear = year;
}

void Transaction::setMajorActor(string actor)
{
	majorActor = actor;
}

char Transaction::getTransactionType() const
{
	return transactionType;
}

int Transaction::getCustomerID() const
{
	return customerId;
}

char Transaction::getMediaType() const
{
	return mediaType;
}

char Transaction::getMovieType() const
{
	return movieType;
}

string Transaction::getTitle() const
{
	return title;
}

string Transaction::getDirector() const
{
	return director;
}

int Transaction::getReleaseMonth() const
{
	return releaseMonth;
}

int Transaction::getReleaseYear() const
{
	return releaseYear;
}

string Transaction::getMajorActor() const
{
	return majorActor;
}

void Transaction::display()
{
	char transType = this->getTransactionType();
	//check movie type to find different type of movie
	char movieType = this->getMovieType();
	switch (transType) {
	case 'B':
		//check movie type to find different type of movie
		switch (movieType) {
		case 'F':
			cout << this->getTransactionType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() << " " << this->getTitle() << ", " << this->getReleaseYear() << endl;
			break;

		case 'D':
			cout << this->getTransactionType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() << " " << this->getDirector() << ", " << this->getTitle() << ", " << endl;
			break;

		case 'C':
			cout << this->getTransactionType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() << " " << this->getReleaseMonth() << " " << this->getReleaseYear() << " " << this->getMajorActor() << endl;
			break;

		}

	case 'R':
		//check movie type to find different type of movie
		switch (movieType) {
		case 'F':
			cout << this->getTransactionType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() << " " << this->getTitle() << ", " << this->getReleaseYear() << endl;
			break;

		case 'D':
			cout << this->getTransactionType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() << " " << this->getDirector() << ", " << this->getTitle() << ", " << endl;
			break;

		case 'C':
			cout << this->getTransactionType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() << " " << this->getReleaseMonth() << " " << this->getReleaseYear() << " " << this->getMajorActor() << endl;
			break;

		}

	case 'I':
		cout << this->getTransactionType() << endl;
		break;

	case 'H':
		cout << this->getTransactionType() << " " << this->getCustomerID() << endl;
		break;

	}

}

string Transaction::toString()
{
	return "a";
}

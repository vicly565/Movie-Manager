#include "Return.h"

Return::Return(char action)
{
	transactionType = action;
}

bool Return::doTrans(BinTree* comedy, BinTree* drama, BinTree* classic, HashTable* customers)
{
	Customer* tempCustomer = customers->retrieveCustomer(this->getCustomerID());

	//checks if customer is in the system
	if (tempCustomer == nullptr) {
		//prints error if not found
		cerr << "Customer not found: " << tempCustomer << endl;

	}
	else {
		char tempMovieType = this->getMovieType();
		Movie* targetMovie;
		Movie* foundMovie;

		//check movie type to find different type of movie
		switch (tempMovieType) {
		case 'F':
			targetMovie = new Comedy(tempMovieType);
			targetMovie->setTitle(this->getTitle());
			targetMovie->setReleaseYear(this->getReleaseYear());

			if (comedy->retrieve(targetMovie, foundMovie)) {//check for the movie
				tempCustomer->returnMovie(foundMovie);
				foundMovie->setStock(foundMovie->getStock() + 1);
				this->setTitle(foundMovie->getTitle());
			}
			else {
				cerr << "Invlaid Movie: " << targetMovie->getTitle() << endl;
				return false;
			}
			break;

		case 'D':
			targetMovie = new Drama(tempMovieType);
			targetMovie->setTitle(this->getTitle());
			targetMovie->setDirector(this->getDirector());

			if (drama->retrieve(targetMovie, foundMovie)) {//check for the movie
				tempCustomer->returnMovie(foundMovie);
				foundMovie->setStock(foundMovie->getStock() + 1);
				this->setTitle(foundMovie->getTitle());
			}
			else {
				cerr << "Invlaid Movie: " << targetMovie->getTitle() << endl;
				return false;
			}
			break;

		case 'C':
			targetMovie = new Classic(tempMovieType);
			targetMovie->setReleaseMonth(this->getReleaseMonth());
			targetMovie->setReleaseYear(this->getReleaseYear());
			targetMovie->setMajorActor(this->getMajorActor());

			if (classic->retrieve(targetMovie, foundMovie)) {//check for the movie
				tempCustomer->returnMovie(foundMovie);
				foundMovie->setStock(foundMovie->getStock() + 1);
				this->setTitle(foundMovie->getTitle());
			}
			else {
				cerr << "Invlaid Movie with major actor: " << targetMovie->getMajorActor() << endl;
				return false;
			}
			break;

		}
	}
}

string Return::toString()
{
		string putBackAsString;
		switch (movieType) {
		case 'F':
			putBackAsString = "Returned: " + title + ", Released in: " + to_string(releaseYear) + ". Media Type: " + mediaType;
			break;
		case 'D':
			putBackAsString = "Returned: " + title + ", Directed by: " + director + ". Media Type: " + mediaType;
			break;
		case 'C':
			putBackAsString = "Returned: " + title + ", Released in: " + to_string(releaseMonth) + " " + to_string(releaseYear);
			putBackAsString = putBackAsString + " Major Actor: " + majorActor + ". Media Type: " + mediaType;
		}
		return putBackAsString;
}

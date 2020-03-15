#include "Borrow.h"

Borrow::Borrow(char action)
{
	transactionType = action;
}

bool Borrow::doTrans(BinTree* comedy, BinTree* drama, BinTree* classic, HashTable* customers)
{
	Customer* tempCustomer = customers->retrieveCustomer(this->getCustomerID());
	Movie* foundMovie = nullptr;
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

			if (comedy->retrieve(targetMovie, foundMovie)) {
				if (foundMovie->getStock() > 0) {
					targetMovie->setDirector(foundMovie->getDirector());
					targetMovie->setTitle(foundMovie->getTitle());
					targetMovie->setReleaseYear(foundMovie->getReleaseYear());
					targetMovie->setStock(foundMovie->getStock());
					tempCustomer->borrowMovie(targetMovie);
					int checkoutStock = foundMovie->getStock();
					checkoutStock--;
					foundMovie->setStock(checkoutStock);//remove 1 from stock
					return true;//transaction successful
				}
				else if(foundMovie->getStock() == 0){
					comedy->displayInStock(targetMovie);
					cout << foundMovie->getTitle() << " out of stock." << endl;
					return false;
				}
			}
			else {
				cerr << "Invalid Movie: " << targetMovie->getTitle() << endl;
				return false;
			}
			break;

		case 'D':
			targetMovie = new Drama(tempMovieType);
			targetMovie->setTitle(this->getTitle());
			targetMovie->setDirector(this->getDirector());

			if (drama->retrieve(targetMovie, foundMovie)) {
				if (foundMovie->getStock() > 0) {
					targetMovie->setDirector(foundMovie->getDirector());
					targetMovie->setTitle(foundMovie->getTitle());
					targetMovie->setReleaseYear(foundMovie->getReleaseYear());
					targetMovie->setStock(foundMovie->getStock());
					tempCustomer->borrowMovie(targetMovie);
					int checkoutStock = foundMovie->getStock();
					checkoutStock--;
					foundMovie->setStock(checkoutStock);//remove 1 from stock
					return true;//transaction successful
				}
				else if (foundMovie->getStock() == 0) {
					comedy->displayInStock(targetMovie);
					cout << foundMovie->getTitle() << " out of stock." << endl;
					return false;
				}
			}
			else {
				cerr << "Invalid Movie: " << targetMovie->getTitle() << endl;
				return false;
			}
			break;

		case 'C':
			targetMovie = new Classic(tempMovieType);
			targetMovie->setReleaseMonth(this->getReleaseMonth());
			targetMovie->setReleaseYear(this->getReleaseYear());
			targetMovie->setMajorActor(this->getMajorActor());

			if (classic->retrieve(targetMovie, foundMovie)) {
				if (foundMovie->getStock() > 0) {
					this->setTitle(foundMovie->getTitle());
					targetMovie->setDirector(foundMovie->getDirector());
					targetMovie->setTitle(foundMovie->getTitle());
					targetMovie->setReleaseYear(foundMovie->getReleaseYear());
					targetMovie->setMajorActor(foundMovie->getMajorActor());
					targetMovie->setReleaseMonth(foundMovie->getReleaseMonth());
					targetMovie->setStock(foundMovie->getStock());
					tempCustomer->borrowMovie(targetMovie);
					int checkoutStock = foundMovie->getStock();
					checkoutStock--;
					foundMovie->setStock(checkoutStock);//remove 1 from stock
					return true;//transaction successful
				}
				else if (foundMovie->getStock() == 0) {
					comedy->displayInStock(targetMovie);
					cout << foundMovie->getTitle() << " out of stock." << endl;
					return false;
				}
			}
			else {
				cerr << "Invalid Movie with major actor: " << targetMovie->getMajorActor() << endl;
				return false;
			}
			break;

		}
	}
}

string Borrow::toString()
{
	string borrowAsString;
	switch (movieType) {
	case 'F':
		borrowAsString = "Borrowed: " + title + ", Released in: " + to_string(releaseYear) + ". Media Type: " + mediaType;
		break;
	case 'D':
		borrowAsString = "Borrowed: " + title + ", Directed by: " + director + ". Media Type: " + mediaType;
		break;
	case 'C':
		borrowAsString = "Borrowed: " + title + ", Released in: " + to_string(releaseMonth) + " " + to_string(releaseYear);
		borrowAsString = borrowAsString + " Major Actor: " + majorActor + ". Media Type: " + mediaType;
	}
	return borrowAsString;
}

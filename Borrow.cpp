#include "Borrow.h"

Borrow::Borrow(char action)
{
	transactionType = action;
}

bool Borrow::doTrans(BinTree* comedy, BinTree* drama, BinTree* classic, HashTable* customers)
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

			foundMovie = new Comedy(tempMovieType);
			if (comedy->retrieve(targetMovie, foundMovie)) {
				if (foundMovie->getStock() > 0) {
					foundMovie->setStock(foundMovie->getStock() - 1);//remove 1 from stock
					tempCustomer->borrowMovie(foundMovie->getTitle());//adds the movie title to the customers borrowed list
					return true;//transaction successful
				}
				else {
					//comedy.displaySameName(targetMovie);
					return false;
				}
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

			foundMovie = new Drama(tempMovieType);
			if (drama->retrieve(targetMovie, foundMovie)) {
				if (foundMovie->getStock() > 0) {
					foundMovie->setStock(foundMovie->getStock() - 1);//remove 1 from stock
					tempCustomer->borrowMovie(foundMovie->getTitle());//adds the movie title to the customers borrowed list
					return true;
				}
				else {
					//drama.displaySameName(targetMovie);
					return false;
				}
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

			foundMovie = new Classic(tempMovieType);
			if (classic->retrieve(targetMovie, foundMovie)) {
				if (foundMovie->getStock() > 0) {
					foundMovie->setStock(foundMovie->getStock() - 1);//remove 1 from stock
					tempCustomer->borrowMovie(foundMovie->getTitle());//adds the movie title to the customers borrowed list
					return true;
				}
				else {
					//classic.displaySameName(targetMovie);
					return false;
				}
			}
			else {
				cerr << "Invlaid Movie with major actor: " << targetMovie->getMajorActor() << endl;
				return false;
			}
			break;

		}
	}
}


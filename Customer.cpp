#include "Customer.h"

Customer::Customer(int id, string lastName, string firstName)
{
	id = id;
	firstName = firstName;
	lastName = lastName;
}

Customer::~Customer()
{
}

bool Customer::addTransaction(string transaction)
{
	history.push_back(transaction);
	return true;
}

void Customer::setId(int custId)
{
	id = custId;
}

void Customer::setLastName(string lastN)
{
	lastName = lastN;
}

void Customer::setFirstName(string firstN)
{
	firstName = firstN;
}

int Customer::getId() const
{
	return id;
}

string Customer::getLastName() const
{
	return lastName;
}

string Customer::getFirstName() const
{
	return firstName;
}

void Customer::borrowMovie(Movie*& movie)
{
	Movie* copy = movie;
	copy->setStock(1);

	int borrowed = getMovieIndex(movie);
	if (hasMovie(movie)) {
		borrowedMovies[borrowed]->setStock(borrowedMovies[borrowed]->getStock() + 1);
	}
	else {
		borrowedMovies.push_back(copy);
	}
}

void Customer::returnMovie(Movie* movie)
{
	int removed = getMovieIndex(movie);
	if (hasMovie(movie)) {
		if (borrowedMovies[removed]->getStock() > 1) {//check if customer has more than 1 copy
			borrowedMovies[removed]->setStock(borrowedMovies[removed]->getStock() - 1);
		}
		else {
			borrowedMovies.erase(borrowedMovies.begin() + removed);//if only has one delete 
		}
	}
	else {
		cout << "Customer does not have the movie" << endl;
	}
}

bool Customer::hasMovie(Movie* movie)
{
	int removed = getMovieIndex(movie);
	if (removed >= 0) {
		return true;
	}
	return false;
}

int Customer::getMovieIndex(Movie* movie)
{
	for (int i = 1; i <= borrowedMovies.size(); i++) {
		if (borrowedMovies[i] == movie) {
			return i-1;//minus 1 because erase uses beginning of vector
		}
	}
	return -1;//return -1 if wasnt found
}


void Customer::display()
{
	cout << id << " " << lastName << " " << firstName;
}

void Customer::displayHistory()
{
	for (int i = 0; i < history.size(); i++) {
		cout << history[i] << endl;
	}
}

ostream& operator<<(ostream& out, const Customer& cust)
{
	out << cust.getId() << " " << cust.getLastName() << " " << cust.getFirstName();
	return out;
}

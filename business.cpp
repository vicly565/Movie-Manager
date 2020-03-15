#include "business.h"

Business::Business()
{
}

Business::~Business()
{
	cout << "destructing business" << endl;
}

void Business::buildMovies(istream& inStream)
{
	//while we're not at the end of the file
	while (!inStream.eof()) {
		Movie* movieForTree = MovieFactory::MakeMovie(inStream);

		//if we were able to make the movie
		//determine which tree to insert the movie into
		if (movieForTree != nullptr) {
			switch (movieForTree->getTypeOfMovie()) {

			case 'F':
				comedyTree.insert(movieForTree);
				break;

			case 'D':
				dramaTree.insert(movieForTree);
				break;

			case 'C':
				classicTree.insert(movieForTree);
				break;

			default:
				cerr << "Unexpected Movie type for tree" << endl;
				break;
			}

		}
	}
}

void Business::buildCustomers(istream& inStream)
{
	int id;
	string firstName;
	string lastName;
	string checkEnd;
	//while we're not at the end of the file
	while (!inStream.eof()) {
		//read in from file
		inStream >> id >> lastName >> firstName;

		//check if ID is valid with 4 digits
		if (id != NULL) {
			if (id < 1000 || id > 9999) {
				cerr << "Invalid Customer ID Number during creation of " << firstName << " " << lastName << endl;
			}
			else {
				Customer* customerForTable = new Customer(id, lastName, firstName);
				customerAccounts.addCustomer(id, customerForTable);
				id = NULL;
				firstName = "";
				lastName = "";
			}
		}
	}
}

void Business::buildTransactions(istream& inStream)
{
	//while we're not at the end of the file
	while (!inStream.eof()) {
		Transaction* queueTransaction = transactionFactory::make_Transaction(inStream);

		//if we were able to make the movie
		//determine which tree to insert the movie into
		if (queueTransaction != nullptr) {
			transactions.push(queueTransaction);
		}
		else {
			cout << "Not a valid transaction." << endl;
		}
	}
}

void Business::executeTransactions()
{
}


const BinTree& Business::getComedyTree() const
{
	return this->comedyTree;
}

const BinTree& Business::getClassicTree() const
{
	return this->classicTree;
}

const HashTable& Business::getCustomers() const
{
	return this->customerAccounts;
}

const BinTree& Business::getDramaTree() const
{
	return this->dramaTree;
}
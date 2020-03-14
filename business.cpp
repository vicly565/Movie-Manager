// ------------------------------------------------ business.cpp -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file contains implementation on the business for the inventory manager program created for
// CSS343's program 4. The Business is to represent a movie rental business where customers can borrow and return DVDs
// -------------------------------------------------------------------------------------------------------------------- 
// 
// Specifications: Each Business contains a BinTree for the comedy movies, classic movies, and the drama movies.
// Additionally each Business contains a hash table of customers, and a queue of transactions that need to be done
// 
// The BinTree has these PUBLIC FUNCTIONS:
//						void buildMovies(istream& inStream); //reads in a  text file to build the movie trees
//						void buildCustomers(istream& inStream); //reads in a text file to build the hashtable
//						void buildTransactions(istream& inStream); //reads in a text file to build the transaction queue
//						void executeTransactions(); //executes all of the transactions
//
//						Additionally all businesses have getters for the data structures that it has
//
// Assumptions: This program assumes that all text files are formatted correctly to how they appear in the specifications
// This program assumes that each binary search tree is sorted based on the sorting conditions provided in the program
// specifications.
// This program also assumes that duplicate customers, and movies are to be discarded.
// 
// --------------------------------------------------------------------------------------------------------------------
#include "business.h"

// ------------------------------------Business()----------------------------------------------- 
// Description
// Business(): Creates a Business object
// preconditions: none
//
// postconditions: a Business object is created
//
// -------------------------------------------------------------------------------------------- 
Business::Business()
{
}

// ------------------------------------~Business()----------------------------------------------- 
// Description
// ~Business(): Destructs a Business object
// preconditions: Business must be created first
//
// postconditions: all memory associated with the business is deallocated by calling the destructors
// on the data structures associated with the business
//
// -------------------------------------------------------------------------------------------- 
Business::~Business()
{
	cout << "destructing business" << endl;
}

// ------------------------------------Functions-----------------------------------------------
// ------------------------------------buildMovies----------------------------------------------- 
// Description
// buildMovies(istream& inStream): Adds movies into the correct bintree after reading them in from a file
// preconditions: Business must be created first
//
// postconditions: The 3 BinTrees are populated with movies from the file
//
// assumptions: The text file is formatted correctly, and duplicate movies need to be removed
//
// -------------------------------------------------------------------------------------------- 
void Business::buildMovies(istream& inStream)
{
	bool notDupe = true;
	//while we're not at the end of the file
	while (!inStream.eof()) {
		Movie* movieForTree = MovieFactory::MakeMovie(inStream);

		//if we were able to make the movie
		//determine which tree to insert the movie into
		if (movieForTree != nullptr) {
			switch (movieForTree->getTypeOfMovie()) {

			case 'F':
				notDupe = comedyTree.insert(movieForTree);

				//deletes duplicate
				if (notDupe == false) {
					delete movieForTree;
					movieForTree = nullptr;
					notDupe = true;
				}
				break;

			case 'D':
				notDupe = dramaTree.insert(movieForTree);

				//deletes duplicate
				if (notDupe == false) {
					delete movieForTree;
					movieForTree = nullptr;
					notDupe = true;
				}
				break;

			case 'C':
				notDupe = classicTree.insert(movieForTree);

				//deletes duplicate
				if (notDupe == false) {
					delete movieForTree;
					movieForTree = nullptr;
					notDupe = true;
				}
				break;

			default:
				cerr << "Unexpected Movie type for tree" << endl;
				break;
			}

		}
	}
}

// ------------------------------------buildCustomers----------------------------------------------- 
// Description
// buildCustomers(istream& inStream): Adds customers into our hashtable after reading them in
// through the text file
// preconditions: none
//
// postconditions: The hashtable is populated
//
// assumptions: the text file is formatted correctly and duplicate customers need to be removed
//
// -------------------------------------------------------------------------------------------- 
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

// ------------------------------------End of Functions-----------------------------------------------

// ------------------------------------Getters-----------------------------------------------
// ------------------------------------getComedyTree----------------------------------------------- 
// Description
// getComedyTree(): returns this business's comedy tree
// preconditions: none
//
// postconditions: The comedy tree is returned
//
// --------------------------------------------------------------------------------------------
const BinTree& Business::getComedyTree() const
{
	return this->comedyTree;
}

// ------------------------------------getClassicTree----------------------------------------------- 
// Description
// getClassicTree(): returns this business's classic tree
// preconditions: none
//
// postconditions: The classic tree is returned
//
// --------------------------------------------------------------------------------------------
const BinTree& Business::getClassicTree() const
{
	return this->classicTree;
}

// ------------------------------------getCustomers----------------------------------------------- 
// Description
// getCustomers(): returns this business's customer hashtable
// preconditions: none
//
// postconditions: The customer hashtable is returned
//
// --------------------------------------------------------------------------------------------
const HashTable& Business::getCustomers() const
{
	return this->customerAccounts;
}

// ------------------------------------getDramaTree----------------------------------------------- 
// Description
// getDramaTree(): returns this business's drama tree
// preconditions: none
//
// postconditions: The drama tree is returned
//
// --------------------------------------------------------------------------------------------
const BinTree& Business::getDramaTree() const
{
	return this->dramaTree;
}

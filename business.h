// ------------------------------------------------ business.h -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This header file contains information on the business for the inventory manager program created for
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
#pragma once
#include "hashtable.h"
#include "bintree.h"
#include "movie.h"
#include "moviefactory.h"
#include "transaction.h"
#include "transactionFactory.h"
#include <queue>;
using namespace std;

class Business
{
public:
	//constructor and destructor
	Business();
	~Business();

	//functions to build the data structure
	void buildMovies(istream& inStream);
	void buildCustomers(istream& inStream);
	void buildTransactions(istream& inStream);

	//function to do the transactions
	void executeTransactions();

	//getters
	const BinTree& getComedyTree() const;
	const BinTree& getDramaTree() const;
	const BinTree& getClassicTree() const;
	const HashTable& getCustomers() const;
private:
	BinTree comedyTree;
	BinTree dramaTree;
	BinTree classicTree;
	HashTable customerAccounts;
	queue<Transaction*> transactions;
};


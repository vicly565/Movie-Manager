#pragma once
#include "hashtable.h"
#include "bintree.h"
#include "movie.h"
#include "moviefactory.h"
#include "Transaction.h"
#include "transactionFactory.h"
#include <queue>;
using namespace std;

class Business
{
public:
	Business();
	~Business();

	void buildMovies(istream& inStream);
	void buildCustomers(istream& inStream);
	void buildTransactions(istream& inStream);
	void executeTransactions();

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
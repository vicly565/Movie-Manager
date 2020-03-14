#pragma once
#include "hashtable.h"
#include "bintree.h"
#include "movie.h"
#include "moviefactory.h"
using namespace std;

class Business
{
public:
	Business();
	~Business();

	void buildMovies(istream& inStream);
	void buildCustomers(istream& inStream);
	void buildTransactions(istream& inStream);

	const BinTree& getComedyTree() const;
	const BinTree& getDramaTree() const;
	const BinTree& getClassicTree() const;
	const HashTable& getCustomers() const;
private:
	BinTree comedyTree;
	BinTree dramaTree;
	BinTree classicTree;
	HashTable customerAccounts;
};


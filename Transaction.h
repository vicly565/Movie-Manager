#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hashtable.h"
#include "bintree.h"
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
using namespace std;
class Transaction
{
public:
	virtual ~Transaction();

	virtual bool doTrans(BinTree* comedy, BinTree* drama, BinTree* classic, HashTable* customers) = 0;

	//Setter methods
	virtual void setTransactionType(char transtype);
	virtual void setCustomerID(int custID);
	virtual void setMediaType(char mediatype);
	virtual void setMovieType(char filmtype);
	virtual void setTitle(string title);
	virtual void setDirector(string director);
	virtual void setReleaseMonth(int month);
	virtual void setReleaseYear(int year);
	virtual void setMajorActor(string actor);

	//Getter methods
	virtual char getTransactionType()const;
	virtual int getCustomerID()const;
	virtual char getMediaType()const;
	virtual char getMovieType()const;
	virtual string getTitle()const;
	virtual string getDirector()const;
	virtual int getReleaseMonth()const;
	virtual int getReleaseYear()const;
	virtual string getMajorActor() const;

    virtual void display();
protected:
	char transactionType;
	int customerId;
	char mediaType;
	char movieType;

	string title;
	string director;
	int releaseMonth;//need this for classic movies
	int releaseYear;
	string majorActor;
};


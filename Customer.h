#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "movie.h"
using namespace std; 

class Customer
{
public:
	Customer(int id, string lastName, string firstName);
	~Customer();

	bool addTransaction(string transaction);
	friend ostream& operator<<(ostream& out, const Customer& cust);

	void setId(int custId);
	void setLastName(string lastN);
	void setFirstName(string firstN);

	int getId()const;
	string getLastName()const;
	string getFirstName()const;
	
	//add or remove movies when calling borrow or return transactions
	void borrowMovie(Movie*& movie);
	void returnMovie(Movie* movie);
	bool hasMovie(Movie* movie);//function to check if the customer has borrowed the movie 
	int getMovieIndex(Movie* movie);

	void display();
	void displayHistory();
private:

	int id;
	string firstName;
	string lastName;
	vector<string> history;
	vector<Movie*> borrowedMovies;
};


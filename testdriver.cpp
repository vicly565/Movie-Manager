#pragma once
#include <iostream>;
#include "movie.h";
#include "classic.h"
#include "comedy.h"
#include "drama.h";
#include "bintree.h";
#include "business.h"

using namespace std;

int main() {
	Business test;
	ifstream infile1("data4movies.txt");
	ifstream infile2("data4customers.txt");
	ifstream infile3("data4commands.txt");
	if (!infile1 || !infile2 || !infile3) {
		cout << "Files could not be opened." << endl;
		return 1;
	}
	test.buildMovies(infile1);
	test.buildCustomers(infile2);
	test.buildTransactions(infile3);
	test.executeTransactions();
}
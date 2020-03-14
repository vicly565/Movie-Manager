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
	HashTable disp;
	ifstream infile1("data4movies.txt");
	ifstream infile2("data4customers.txt");
	test.buildMovies(infile1);
	test.buildCustomers(infile2);
	test.getClassicTree().display();
	test.getComedyTree().display();
	test.getDramaTree().display();
	disp = test.getCustomers();
	disp.display();
}
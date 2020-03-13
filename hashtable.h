#pragma once
#include <iostream>
#include "customer.h"

using namespace std;

class HashTable
{
	//linked list of customers for when collisions occur
	struct CustomerNode {
		Customer* data;
		int id;
		CustomerNode* next;
	};
	//0.52% chance of error according to planetmath.org
	//on good hash table primes
	static int const PRIMEHASH = 193;

public:
	HashTable();
	~HashTable();

	Customer* retrieveCustomer(int id) const;
	void addCustomer(int id, Customer* theCustomer);

private:
	CustomerNode* table[PRIMEHASH];



	//helper for destructor
	void makeEmpty();
	//helper for constructor
	void buildTable();
};


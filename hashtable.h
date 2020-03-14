// ------------------------------------------------ hashtable.h -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This header file contains information on the hashtable data structure, which is used to store customer
// information. This hashtable contains seperate hashing, meaning that if there is a collision a linked list will be
// made in its place. Each hash key is identified by the customer ID
// -------------------------------------------------------------------------------------------------------------------- 
// 
// Specifications: Each hash table contains a structure called CustomerNode which are nodes created for the linked list
// of customers in the event that there are collisions. Each has table also contains a constant PRIMEHASH which is a prime
// number used for the hashing algorithm
// 
// The HashTable has these PUBLIC FUNCTIONS:
//								Customer* retrieveCustomer(int id) const; //get the customer from the hash table
//								void addCustomer(int id, Customer* theCustomer); // add customer to the hash table
//								void display(); //display all customers in the hash table
//								
//
// The HashTable has these PRIVATE HELPER FUNCTIONS:
//								void makeEmpty(); //helper for destructor
//								void buildTable(); //helper for constructor
//
// Assumptions: This data structure assumes that no duplicate customer IDs will be stored
// 
// --------------------------------------------------------------------------------------------------------------------
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

	//get the customer from the hash table
	Customer* retrieveCustomer(int id) const;
	//add customer to the hash table
	void addCustomer(int id, Customer* theCustomer);

	//display all customers in the hash table
	void display();

	//helper for destructor
	void makeEmpty();

private:
	//array that the hashtable is stored in
	CustomerNode* table[PRIMEHASH];



	//helper for constructor
	void buildTable();
};


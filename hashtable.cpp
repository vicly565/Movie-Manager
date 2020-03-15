// ------------------------------------------------ hashtable.cpp -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This header file contains implementation of the hashtable data structure, which is used to store customer
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
#include "hashtable.h"

// ------------------------------------HashTable()----------------------------------------------- 
// Description
// HashTable(): Creates a HashTable object by calling the buildTable method
// preconditions: none
//
// postconditions: a Hash Table is created
//
// -------------------------------------------------------------------------------------------- 
HashTable::HashTable()
{
	//builds the hash table
	buildTable();
}

// ------------------------------------~HashTable()----------------------------------------------- 
// Description
// ~HashTable(): Destructor for the hash table. Frees all memory associated with the hashtable
// preconditions: HashTable is an existing object
//
// postconditions: Hash table is deleted, and memory is deallocated
//
// -------------------------------------------------------------------------------------------- 
HashTable::~HashTable()
{
	makeEmpty();
}

// ------------------------------------Functions-----------------------------------------------
// ------------------------------------retrieveCustomer----------------------------------------------- 
// Description
// retrieveCustomer(int id): Retrieves the customer at the ID that is passed in
// preconditions: none
//
// postconditions: a pointer to the customer is returned. If customer is not found a null pointer
// is returned instead
//
// --------------------------------------------------------------------------------------------
Customer* HashTable::retrieveCustomer(int id) const
{
	//get hash value of the ID
	int hash = (id % PRIMEHASH);

	if (table[hash] == nullptr) {
		//customer ID is not in our database
		return nullptr;
	}

	//otherwise we need to look for the customer
	//in the linked list at current index
	CustomerNode* curr = table[hash];
	while (curr != nullptr) {

		//if the current ID matches what we're looking for return it
		if (id == curr->id) {
			return curr->data;
		}
		//otherwise continue traversing
		curr = curr->next;
	}

	//we reach here if customer was not found in our hashtable
	return nullptr;
}

// ------------------------------------addCustomer----------------------------------------------- 
// Description
// addCustomer(int id, Customer* theCustomer): adds the customer that is passed in into the hashtable
// preconditions: none
//
// postconditions: The customer is added to the table if the ID is not a duplicate.
//
// assumption: duplicate customers are deleted.
//
// --------------------------------------------------------------------------------------------
void HashTable::addCustomer(int id, Customer* theCustomer)
{
	//get a hash value
	int hash = (id % PRIMEHASH);

	//create a customer node for the table
	CustomerNode* adding = new CustomerNode;
	adding->data = theCustomer;
	adding->id = id;
	adding->next = nullptr;

	if (table[hash] == nullptr) {
		//if the current index we hashed is empty we insert here
		table[hash] = adding;
	}
	else {
		//traverse to end linked list at the index
		CustomerNode* curr = table[hash];

		do{
			//check to make sure the customer ID doesn't already exist
				if (adding->id == curr->id) {
					cerr << "Customer ID: " << id << " already exists. Cannot add to ";
					cout << adding->data->getLastName() << " " << adding->data->getFirstName() << " database." << endl;
					//delete data associated with the duplicate
					delete adding->data;
					delete adding;
					adding = nullptr;
					return;

			}
				//move to the next node in the list
			curr = curr->next;
		} while (curr->next != nullptr);

		//once we break out of the while statement the next node is end of the linked list
		curr->next = adding;
	}
}

// ------------------------------------display----------------------------------------------- 
// Description
// dispay(): prints all customers that are in the hash table, based on how they were read in
// preconditions: none
//
// postconditions: The customer are printed to the console
//
// --------------------------------------------------------------------------------------------
void HashTable::display()
{
	//temp customer node for traversale
	CustomerNode* temp;
	for (int i = 0; i < PRIMEHASH; i++) {

		//set temp to the current index
		temp = table[i];

		while (temp != nullptr) {
			//while temp isn't a nullpointer print out the customer info
			//then go to the next data in the linked list of customers
			cout << *temp->data << endl;
			temp = temp->next;
		}
	}
}
// ------------------------------------End of functions--------------------------------

// ------------------------------------Helper Functions-----------------------------------------------
// ------------------------------------makeEmpty----------------------------------------------- 
// Description
// makeEmpty(): deallocates memory associated with the hash table
// preconditions: hash table exists, and destructor is called
//
// postconditions: memory associated with the hash table is deallocated
//
// --------------------------------------------------------------------------------------------
void HashTable::makeEmpty()
{
	//for everything in the size of this hash table
	for (int i = 0; i < PRIMEHASH; i++) {
		//holder for deleting.
		//i is the index of the head for the current spot
		CustomerNode* del = table[i];

		//while the head at the current index isn't a null pointer
		while (table[i] != nullptr) {

			//assign a new head to the linked list
			table[i] = table[i]->next;

			//delete the customer inside the data
			//then we delete the current node
			delete del->data;
			delete del;
			del = nullptr;

			//move where we're deleting to the new head
			del = table[i];
		}
	}
}

// ------------------------------------buildTable----------------------------------------------- 
// Description
// buildTable(): sets every index in the hashtable to nullptr
// preconditions: constructor is called
//
// postconditions: Hash Table is created with an array of null pointers
//
// --------------------------------------------------------------------------------------------
void HashTable::buildTable()
{
	//sets everything in the table to null
	for (int i = 0; i < PRIMEHASH; i++) {
		table[i] = nullptr;
	}
}
// ------------------------------------End of Helper Functions----------------------------------

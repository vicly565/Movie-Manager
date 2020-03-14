#include "hashtable.h"

HashTable::HashTable()
{
	buildTable();
}

HashTable::~HashTable()
{
	cout << "destructing table" << endl;
	makeEmpty();
}

Customer* HashTable::retrieveCustomer(int id) const
{
	//get hash value
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

		while (curr->next != nullptr) {
			//check to make sure the customer ID doesn't already exist
			if (id == curr->id) {
				cerr << "Customer ID: " << id << " already exists. Cannot add to customer database." << endl;
				//delete info associated with the duplicate
				delete adding->data;
				delete adding;
				adding = nullptr;
			}
			curr = curr->next;
		}

		//once we break out of the while statement the next node is end of the linked list
		curr->next = adding;
	}
}

void HashTable::display()
{
	CustomerNode* temp;
	for (int i = 0; i < PRIMEHASH; i++) {
		temp = table[i];
		while (temp != nullptr) {
			cout << *temp->data << endl;
			temp = temp->next;
		}
	}
}

void HashTable::makeEmpty()
{
	//for everything in the size of this hash table
	for (int i = 0; i < PRIMEHASH; i++) {
		//holder for deleting i should be head of that index
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

void HashTable::buildTable()
{
	//sets everything in the table to null
	for (int i = 0; i < PRIMEHASH; i++) {
		table[i] = nullptr;
	}
}

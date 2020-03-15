#include "History.h"

History::History(char action)
{
	transactionType = action;
}

bool History::doTrans(BinTree* comedy, BinTree* drama, BinTree* classic, HashTable* customers)
{
	Customer* tempCustomer = customers->retrieveCustomer(this->getCustomerID());

	//checks if customer is in the system
	if (tempCustomer == nullptr) {
		//prints error if not found
		cerr << "Customer not found: " << tempCustomer << endl;
		return false;
	}
	else {
		tempCustomer->displayHistory(); 
	}
	return true;
}

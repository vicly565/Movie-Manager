#pragma once
#include "Transaction.h"

class Inventory : public Transaction
{
public:
	Inventory(char action);

	bool doTrans(BinTree* comedy, BinTree* drama, BinTree* classic, HashTable* customers);
	void checkInventory(BinTree* comedy, BinTree* drama, BinTree* classic); //checks the inventory of all the items in the store

};
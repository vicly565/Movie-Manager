#pragma once
#include "Transaction.h"

class Borrow : public Transaction
{
public:
	Borrow(char action);

	bool doTrans(BinTree* comedy, BinTree* drama, BinTree* classic, HashTable* customers); //decreases inventory by 1, checks first if there is inventory

};


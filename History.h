#pragma once
#include "Transaction.h"

class History : public Transaction
{
public:
	History(char action);
	
	bool doTrans(BinTree* comedy, BinTree* drama, BinTree* classic, HashTable* customers); //shows the history of transactions for a customer

};


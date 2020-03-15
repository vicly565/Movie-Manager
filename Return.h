#pragma once
#include "Transaction.h"

class Return : public Transaction
{
public:
	Return(char action);

	bool doTrans(BinTree* comedy, BinTree* drama, BinTree* classic, HashTable* customers); //increases inventory of the certain movie by one
	string toString();
};

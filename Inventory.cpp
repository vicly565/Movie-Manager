#include "Inventory.h"

Inventory::Inventory(char action)
{
	transactionType = action;
}

bool Inventory::doTrans(BinTree* comedy, BinTree* drama, BinTree* classic, HashTable* customers)
{
	checkInventory(comedy, drama, classic);
	return true;
}

void Inventory::checkInventory(BinTree* comedy, BinTree* drama, BinTree* classic)
{
	comedy->display();//displays everything from the comedy BST
	classic->display();//displays everything from the classic BST
	drama->display();//displays everyting from the drama BST
}

#include <iostream>
#include "Borrow.h"
#include "Return.h"
#include "Inventory.h"
#include "History.h"
#include "Transaction.h"
#include <string>
class transactionFactory
{
public:
	static Transaction* make_Transaction(istream& inStream);
};
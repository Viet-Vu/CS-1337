#include "RegularAccount.h"

// This function passes the values of a Regular Account creation to the Account constructor.
RegularAccount::RegularAccount(string nam, double amnt, Date d):Account(nam, amnt, d) {}

// This block prints the unique indicator for a Regular Account.
void RegularAccount::print() const
{
   cout << endl << "Regular account";
   this->Account::print();
}
#include "RegularAccount.h"

RegularAccount::RegularAccount(string nam, double amnt, Date d):Account(nam, amnt, d) {}

void RegularAccount::print() const
{
   cout << endl << "Regular account";
   this->Account::print();
}
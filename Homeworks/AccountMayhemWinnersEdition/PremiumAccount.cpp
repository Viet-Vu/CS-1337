#include "PremiumAccount.h"

const double PremiumAccount::MIN_BALANCE = 1000;

PremiumAccount::PremiumAccount(string nam, double amnt, Date d): Account(nam, amnt, d) {}

bool PremiumAccount::withdraw(double amnt, Date d)
{
   if (balance < (amnt + MIN_BALANCE))
      return false;

   balance -= amnt;

   #ifdef EXTRA_CREDIT
      Transaction t = {d, 2, amnt};
      this->recordTransaction(t);
   #endif

   return true;
}

double PremiumAccount::getMinBalance()
{
   return MIN_BALANCE;
}

void PremiumAccount::print() const
{
   cout << endl << "Premium account";
   this->Account::print();
}
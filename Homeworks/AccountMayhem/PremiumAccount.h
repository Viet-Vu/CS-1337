#ifndef ACCOUNTMAYHEM_PREMIUMACCOUNT_H
#define ACCOUNTMAYHEM_PREMIUMACCOUNT_H

#include "Account.h"
#include "Date.h"

class PremiumAccount:public Account
{
private:
   static const double MIN_BALANCE;
public:
   PremiumAccount(string nam, double amnt, Date d);
   bool withdraw(double amnt, Date d) override;
   static double getMinBalance();
   void print() const override;
};

#endif

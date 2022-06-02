#ifndef ACCOUNTMAYHEMWINNERSEDITION_PREMIUMACCOUNT_H
#define ACCOUNTMAYHEMWINNERSEDITION_PREMIUMACCOUNT_H

#include "Account.h"
#include "Date.h"
#include "Common.h"

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

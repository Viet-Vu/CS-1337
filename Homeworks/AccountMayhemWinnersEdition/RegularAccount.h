#ifndef ACCOUNTMAYHEMWINNERSEDITION_REGULARACCOUNT_H
#define ACCOUNTMAYHEMWINNERSEDITION_REGULARACCOUNT_H

#include "Account.h"
#include "Common.h"

class RegularAccount:public Account
{
public:
   RegularAccount(string nam, double amnt, Date d);
   void print() const override;
};

#endif

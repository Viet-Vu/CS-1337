#ifndef ACCOUNTMAYHEM_REGULARACCOUNT_H
#define ACCOUNTMAYHEM_REGULARACCOUNT_H

#include "Account.h"

class RegularAccount:public Account
{
public:
   RegularAccount(string nam, double amnt, Date d);
   void print() const override;
};

#endif

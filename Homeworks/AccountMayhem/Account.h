#ifndef ACCOUNTMAYHEM_ACCOUNT_H
#define ACCOUNTMAYHEM_ACCOUNT_H

#include <string>
#include "Date.h"

using namespace std;

struct Transaction
{
   Date date;
   int transactionType;
   double amount;
};

class Account
{
private:
   int accountNumber;
   string ownerName;
protected:
   double balance;
   static int numberAccounts;
   Transaction *transactionHistory;
   int numberTransactions;
   #ifdef EXTRA_CREDIT
      void recordTransaction(Transaction transact);
   #endif
public:
   Account(string nam, double bal, Date d);
   virtual bool withdraw(double amount, Date date_);
   bool deposit(double amount, Date date_);
   int getAccountNumber() const;
   double getBalance() const;
   static int getNumberAccounts();
   #ifdef EXTRA_CREDIT
      void printTransactions() const;
   #endif
   virtual void print() const;
};

#endif

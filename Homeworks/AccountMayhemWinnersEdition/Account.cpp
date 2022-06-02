#include <iomanip>
#include "Account.h"

using namespace std;

int Account::numberAccounts = 0;

Account::Account(string nam, double bal, Date d)
{
   ownerName = nam;
   balance = bal;

   accountNumber = numberAccounts + 1000;
   numberAccounts++;

   #ifdef EXTRA_CREDIT
      Transaction *t = new Transaction {d, 0, bal};
      transactionHistory = {t};
      numberTransactions = 1;
   #endif
}

bool Account::withdraw(double amount, Date date_)
{
   if (balance < amount)
      return false;

   balance -= amount;

   #ifdef EXTRA_CREDIT
      Transaction t = {date_, 2, amount};
      this->recordTransaction(t);
   #endif

   return true;
}

bool Account::deposit(double amount, Date date_)
{
   if (amount < 0)
      return false;

   balance += amount;

   #ifdef EXTRA_CREDIT
      Transaction t = {date_, 1, amount};
      this->recordTransaction(t);
   #endif

   return true;
}

int Account::getAccountNumber() const
{
   return accountNumber;
}

double Account::getBalance() const
{
   return balance;
}

int Account::getNumberAccounts()
{
   return numberAccounts;
}

void Account::print() const
{
   cout << ", #: " << accountNumber << ", Name: " << ownerName << ", Balance: " << fixed << setprecision(2) << balance << " Galactic units" << endl;
}

#ifdef EXTRA_CREDIT
void Account::recordTransaction(Transaction t)
{
   Transaction *arr = transactionHistory;
   transactionHistory = new Transaction[numberTransactions++];

   for (int i = 0; i < (numberTransactions - 1); i++)
      transactionHistory[i] = arr[i];

   transactionHistory[numberTransactions - 1] = t;

   delete[] arr;
}

void Account::printTransactions() const
{
   double *balances = new double[numberTransactions];
   for (int i = 0; i < numberTransactions; i++)
   {
      if (transactionHistory[i].transactionType == 0)
         balances[i] = transactionHistory[i].amount;
      else if (transactionHistory[i].transactionType == 1)
         balances[i] = balances[i - 1] + transactionHistory[i].amount;
      else
         balances[i] = balances[i - 1] - transactionHistory[i].amount;
   }

   string transactionType[] = {"Creation", "Deposit", "Withdraw"};

   cout << "Transaction history:" << endl << "-------------------" << endl;
   for (int i = 0; i < numberTransactions; i++)
   {
      cout << "Date: "; transactionHistory[i].date.print();
      cout << ", Amount: " << fixed << setprecision(2) << transactionHistory[i].amount << ", type: " << transactionType[transactionHistory[i].transactionType] << ", New balance: " << balances[i] << endl;
   }
}
#endif
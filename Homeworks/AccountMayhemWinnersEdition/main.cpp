#include <iostream>
#include <iomanip>

#include "Date.h"
#include "Account.h"
#include "RegularAccount.h"
#include "PremiumAccount.h"

using namespace std;

int getMenuChoice();
Date getDate(string date);
void createAccount(Account *arr[], int size, bool isRegular);
void depositWithdraw(Account *arr[], int size, bool isDeposit);
void printAccounts(Account *arr[], int size);

int main()
{
   const int MAX_NUM_ACCOUNTS = 5;
   Account *accountArray[MAX_NUM_ACCOUNTS];

   for (int i = 0; i < MAX_NUM_ACCOUNTS; i++)
      accountArray[i] = nullptr;

   for (int menuChoice = getMenuChoice(); menuChoice != 6; menuChoice = getMenuChoice())
   {
      if (menuChoice == 1)
         createAccount(accountArray, MAX_NUM_ACCOUNTS, true);
      else if (menuChoice == 2)
         createAccount(accountArray, MAX_NUM_ACCOUNTS, false);
      else if (menuChoice == 3)
         depositWithdraw(accountArray, MAX_NUM_ACCOUNTS, true);
      else if (menuChoice == 4)
         depositWithdraw(accountArray, MAX_NUM_ACCOUNTS, false);
      else if (menuChoice == 5)
         printAccounts(accountArray, MAX_NUM_ACCOUNTS);
   }

   return 0;
}

int getMenuChoice()
{
   int menuChoice;
   cout << endl << "1->Create regular accnt, 2->Create premium accnt, 3->Deposit to accnt" << endl << "4->Withdraw from accnt, 5->Print info accnts, 6->Quit" << endl;
   cin >> menuChoice;

   return menuChoice;
}

Date getDate(string date)
{
   string month = "", day = "", year = "", hour = "";
   for (int i = 0, count = 0; i < date.length(); i++)
   {
      if (count == 0)
         if (date[i] != '/')
            month += date[i];
         else
            count++;
      else if (count == 1)
         if (date[i] != '/')
            day += date[i];
         else
            count++;
      else if (count == 2)
         if (date[i] != '/')
            year += date[i];
         else
            count++;
      else if (count == 3)
         hour += date[i];
   }

   Date d;
   d.set(stoi(month), stoi(day), stoi(year), stoi(hour));
   return d;
}

void createAccount(Account *arr[], int size, bool isRegular)
{
   int ind = Account::getNumberAccounts();
   if (ind == size)
   {
      cout << "Max number of accounts reached, cannot add a new account" << endl;
      return;
   }

   string ownerName;
   cout << "Enter owner's name: ";
   cin >> ownerName;

   string date;
   cout << "Enter date, in the mm/dd/yyyy/hh format: ";
   cin >> date;

   double amount;
   cout << "Enter amount: ";
   cin >> amount;

   if (amount < 0)
   {
      cout << "Amount cannot be negative, account creation not executed" << endl;
      return;
   }

   Date d = getDate(date);
   if (isRegular)
   {
      RegularAccount *acc = new RegularAccount(ownerName, amount, d);
      arr[ind] = acc;
   }
   else
   {
      if (amount < 1000)
      {
         cout << "Insufficient amount, you need at least " << fixed << setprecision(2) << PremiumAccount::getMinBalance() << " Galactic units to open a premium account" << endl;
         return;
      }

      PremiumAccount *acc = new PremiumAccount(ownerName, amount, d);
      arr[ind] = acc;
   }

   cout << "Account created: ";
   arr[ind]->print();
}

void depositWithdraw(Account *arr[], int size, bool isDeposit)
{
   int accNum;
   cout << "Enter account number: ";
   cin >> accNum;

   int index = 0;
   for (; index < size; index++)
   {
      if (arr[index] == nullptr)
         index = 5;
      else if (arr[index]->getAccountNumber() == accNum)
         break;
   }

   if (index >= size)
   {
      cout << "No such account" << endl;
      return;
   }

   string date;
   cout << "Enter date, in the mm/dd/yyyy/hh format: ";
   cin >> date;

   double amount;
   cout << "Enter amount: ";
   cin >> amount;

   Date d = getDate(date);
   if (isDeposit)
   {
      if (amount < 0)
      {
         cout << "Amount cannot be negative, deposit not executed" << endl;
         return;
      }

      arr[index]->deposit(amount, d);
      cout << "Deposit executed: ";
      arr[index]->print();
   }
   else
   {
      if (amount < 0)
      {
         cout << "Amount cannot be negative, withdraw not executed" << endl;
         return;
      }
      else if (!arr[index]->withdraw(amount, d))
      {
         cout << "Insufficient balance, withdrawal not executed" << endl;
         return;
      }

      cout << "Withdraw executed: ";
      arr[index]->print();
   }
}

void printAccounts(Account *arr[], int size)
{
   cout << "Accounts" << endl << "========" << endl;

   for (int i = 0; i < size; i++)
      if (arr[i] != nullptr)
      {
         arr[i]->print();

         #ifdef EXTRA_CREDIT
            arr[i]->printTransactions();
         #endif
      }
}
/*
 * Program Name: Homework 10: Section 1.13 - Account Inheritance and Separation
 * Author: Viet Vu
 * Date: April 26, 2022
 * Program Description: This program is designed to use multiple .cpp files to manage an Account array with varying
 *                      Account types, Regular and Premium.
 */

#include <iomanip>
#include "Account.h"

using namespace std;

// This line initializes the number of Accounts to zero.
int Account::numberAccounts = 0;

// This function represents the Account constructor used throughout the program.
Account::Account(string nam, double bal, Date d)
{
   // This block sets the ownerName and balance according to the given values.
   ownerName = nam;
   balance = bal;

   // This block sets the accountNumber to its appropriate value and increases the numberAccounts value.
   accountNumber = numberAccounts + 1000;
   numberAccounts++;
}

// This function withdraws a given amount from an Account.
bool Account::withdraw(double amount, Date date_)
{
   // This block returns false if there is not enough balance within the Account.
   if (balance < amount)
      return false;

   balance -= amount;
   return true;
}

// This function deposits a given amount to an Account.
bool Account::deposit(double amount, Date date_)
{
   // This block returns false if the given amount is negative.
   if (amount < 0)
      return false;

   balance += amount;
   return true;
}

// This function returns the accountNumber of an Account.
int Account::getAccountNumber() const
{
   return accountNumber;
}

// This function returns the balance of an Account.
double Account::getBalance() const
{
   return balance;
}

// This function returns the total number of Accounts.
int Account::getNumberAccounts()
{
   return numberAccounts;
}

// This function prints the contents of an Account.
void Account::print() const
{
   cout << ", #: " << accountNumber << ", Name: " << ownerName << ", Balance: " << fixed << setprecision(2) << balance << " Galactic units" << endl;
}
/*
 * Program Name: Homework 10: Section 1.13 - Account Inheritance and Separation
 * Author: Viet Vu
 * Date: April 26, 2022
 * Program Description: This program is designed to use multiple .cpp files to manage an Account array with varying
 *                      Account types, Regular and Premium.
 */

#include "PremiumAccount.h"

// This line sets the value of the minimum balance required to withdraw from or create a Premium Account.
const double PremiumAccount::MIN_BALANCE = 1000;

// This function passes the values of a Premium Account creation to the Account constructor.
PremiumAccount::PremiumAccount(string nam, double amnt, Date d): Account(nam, amnt, d) {}

// This function withdraws from a Premium Account with a given amount.
bool PremiumAccount::withdraw(double amnt, Date d)
{
   // This block returns false if the withdrawal would take an Account's balance below the minimum balance threshold.
   if (balance < (amnt + MIN_BALANCE))
      return false;

   balance -= amnt;
   return true;
}

// This block returns the minimum balance for a Premium Account.
double PremiumAccount::getMinBalance()
{
   return MIN_BALANCE;
}

// This block prints the unique indicator for a Premium Account.
void PremiumAccount::print() const
{
   cout << endl << "Premium account";
   this->Account::print();
}
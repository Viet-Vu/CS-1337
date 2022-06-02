/*
 * Program Name: Homework 7, Section 1.10 - Bank Transaction Management
 * Author: Viet Vu
 * Date: April 3, 2022
 * Program Description: This program is designed to allow users to create multi-owner bank accounts and withdraw and
 *                      deposit money according to some specifications. This program also utilizes OOP to function.
 */

#include "Account.h"

using namespace std;

// This line initializes the account number to 1000.
int Account::accountCounter = 1000;

// This function is a constructor for an Account object.
Account::Account(int numberOwners, double amount)
{
   accountNumber = accountCounter;
   numOwners = numberOwners;
   ownerPtr = new Person[numOwners];
   balance = amount;

   accountCounter++;
}

// This function is the destructor for the Account object.
Account::~Account()
{
   delete[] ownerPtr;
}

// This function is used to withdraw a given dollar amount from an Account object.
int Account::withdraw(double amount)
{
   if (amount > balance)
      return 1;
   if (amount <= 0)
      return 2;

   balance -= amount;
   return 0;
}

// This function is used to deposit a given dollar amount to an Account object.
int Account::deposit(double amount)
{
   if (amount <= 0)
      return 1;

   balance += amount;
   return 0;
}

// This function is used to create an owner within an Account object's owner array.
void Account::setOwner(int ind, Person p)
{
   ownerPtr[ind] = p;
}

// This function is used to gather an owner from an Account object.
Person Account::getOwner(int ind) const
{
   return ownerPtr[ind];
}

// This function is used to gather the account number of an Account object.
int Account::getAccountNumber() const
{
   return accountNumber;
}

// This function is used to gather the balance of an Account object.
double Account::getBalance() const
{
   return balance;
}

// This function is used to gather the number of owners of an Account object.
int Account::getNumOwners() const
{
   return numOwners;
}
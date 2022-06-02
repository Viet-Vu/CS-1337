/*
 * Program Name: Homework 9, Section 1.12 - Transaction File Management
 * Author: Viet Vu
 * Date: April 15, 2022
 * Program Description: This program is designed to read a file and create account object each with their own unique
 *                      transactions and their various corresponding data.
 */

#include "Account.h"

// This function represents the Account constructor. It initializes every numeric value to 0 and every ptr to nullptr.
Account::Account()
{
   accountNumber = 0;
   numOwners = 0;
   balance = 0;
   numTransactions = 0;

   ownerPtr = nullptr;
   transacPtr = nullptr;
}

// This function sets the accountNumber and numOwners variable, then dynamically creates Person array with numOwners and sets the balance to 0.
void Account::setAccount(int accountNumber_, int numOwners_)
{
   accountNumber = accountNumber_;
   numOwners = numOwners_;

   Person *ownerArr = new Person[numOwners];
   ownerPtr = ownerArr;

   balance = 0;
}

// This function sets the owner in the Person owner array with its corresponding index.
void Account::setOwner(int ind, Person p)
{
   ownerPtr[ind] = p;
}

// This function gathers the owner of a certain index within the Person owner array.
Person Account::getOwner(int ind) const
{
   return ownerPtr[ind];
}

// This function gathers the account number.
int Account::getAccountNumber() const
{
   return accountNumber;
}

// This function gathers the number of owners.
int Account::getNumOwners() const
{
   return numOwners;
}

// This function sets the Transaction array with a given Transaction array.
void Account::setTransacPtr(Transaction *transacPtr_)
{
   transacPtr = transacPtr_;
}

// This function gathers the number of transactions.
int Account::getNumTransactions() const
{
   return numTransactions;
}

// This function sets the number of transactions with the given value.
void Account::setNumTransactions(int numTransactions_)
{
   numTransactions = numTransactions_;
}

// Ths function gathers a Transaction within the Transaction array at a given index.
Transaction Account::getTransaction(int ind) const
{
   return transacPtr[ind];
}
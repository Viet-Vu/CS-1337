/*
 * Program Name: Homework 10: Section 1.13 - Account Inheritance and Separation
 * Author: Viet Vu
 * Date: April 26, 2022
 * Program Description: This program is designed to use multiple .cpp files to manage an Account array with varying
 *                      Account types, Regular and Premium.
 */

#include <iostream>
#include <iomanip>

#include "Date.h"
#include "Account.h"
#include "RegularAccount.h"
#include "PremiumAccount.h"

using namespace std;

// These are the function prototypes in the general order in which they appear.
int getMenuChoice();
Date getDate(string date);
void createAccount(Account *arr[], int size, bool isRegular);
void depositWithdraw(Account *arr[], int size, bool isDeposit);
void printAccounts(Account *arr[], int size);

// This function is the main function. It generally follows the guidelines set by ZyBooks.
int main()
{
   // This establishes the Account array and its maximum size.
   const int MAX_NUM_ACCOUNTS = 5;
   Account *accountArray[MAX_NUM_ACCOUNTS];

   // This block initializes all elements of the Account array to nullptr.
   for (int i = 0; i < MAX_NUM_ACCOUNTS; i++)
      accountArray[i] = nullptr;

   // This block loops through the user's menu of choices until they choose to exit.
   // This block uses respective functions to process the user's menu choice.
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

// This function gathers the user's menu of choices.
int getMenuChoice()
{
   // This block outputs the user's menu of choices and gather's the user's choice.
   int menuChoice;
   cout << endl << "1->Create regular accnt, 2->Create premium accnt, 3->Deposit to accnt" << endl << "4->Withdraw from accnt, 5->Print info accnts, 6->Quit" << endl;
   cin >> menuChoice;

   return menuChoice;
}

// This function converts a date string into a proper Date object.
Date getDate(string date)
{
   string month = "", day = "", year = "", hour = "";
   // This line loops through the whole date string.
   for (int i = 0, count = 0; i < date.length(); i++)
   {
      // This block builds the month string from the beginning of the string to the first '/'.
      if (count == 0)
         if (date[i] != '/')
            month += date[i];
         else
            count++;
      // This block builds the day string from the first '/' to the second '/'.
      else if (count == 1)
         if (date[i] != '/')
            day += date[i];
         else
            count++;
      // This block builds the year string from the second '/' to the third '/'.
      else if (count == 2)
         if (date[i] != '/')
            year += date[i];
         else
            count++;
      // This block builds the hour string from the third '/' to the end of the string.
      else if (count == 3)
         hour += date[i];
   }

   // This block creates the Date object with the gathered strings.
   Date d;
   d.set(stoi(month), stoi(day), stoi(year), stoi(hour));
   return d;
}

// This function represents the user's choice to create a Regular or Premium Account.
void createAccount(Account *arr[], int size, bool isRegular)
{
   // This block uses numAccounts to determine if the maximum number of Accounts as been reached.
   int ind = Account::getNumberAccounts();
   if (ind == size)
   {
      cout << "Max number of accounts reached, cannot add a new account" << endl;
      return;
   }

   // This block gather's the user's owner name.
   string ownerName;
   cout << "Enter owner's name: ";
   cin >> ownerName;

   // This block gathers the user's Account creation date.
   string date;
   cout << "Enter date, in the mm/dd/yyyy/hh format: ";
   cin >> date;

   // This block gathers the user's Account starting balance.
   double amount;
   cout << "Enter amount: ";
   cin >> amount;

   // This block returns an error message if the starting balance is negative.
   if (amount < 0)
   {
      cout << "Amount cannot be negative, account creation not executed" << endl;
      return;
   }

   // This line converts the date string into a Date object.
   Date d = getDate(date);
   // This block represents the user's choice to create a Regular Account and places it into the Account array.
   if (isRegular)
   {
      RegularAccount *acc = new RegularAccount(ownerName, amount, d);
      arr[ind] = acc;
   }
   // This block represents the user's choice to create a Premium Account and places it into the Account array.
   else
   {
      // This block returns an error message if the starting Account balance is less than the minimum value.
      if (amount < PremiumAccount::getMinBalance())
      {
         cout << "Insufficient amount, you need at least " << fixed << setprecision(2) << PremiumAccount::getMinBalance() << " Galactic units to open a premium account" << endl;
         return;
      }

      PremiumAccount *acc = new PremiumAccount(ownerName, amount, d);
      arr[ind] = acc;
   }

   // This block outputs the successful Account creation message.
   cout << "Account created: ";
   arr[ind]->print();
}

// This function represents the user's choice to either deposit or withdraw from an Account.
void depositWithdraw(Account *arr[], int size, bool isDeposit)
{
   // This block gathers the user's Account number that they wish to deposit into or withdraw from.
   int accNum;
   cout << "Enter account number: ";
   cin >> accNum;

   // This block goes through the Account array and searches for the given Account number.
   int index = 0;
   for (; index < size; index++)
   {
      if (arr[index] == nullptr)
         index = 5;
      else if (arr[index]->getAccountNumber() == accNum)
         break;
   }

   // This block returns an error message if the Account was not found.
   if (index >= size)
   {
      cout << "No such account" << endl;
      return;
   }

   // This block gathers the user's Transaction date.
   string date;
   cout << "Enter date, in the mm/dd/yyyy/hh format: ";
   cin >> date;

   // This block gathers the user's deposit or withdraw amount.
   double amount;
   cout << "Enter amount: ";
   cin >> amount;

   // This line converts the date string into a Date object.
   Date d = getDate(date);
   // This block represents the user's choice to deposit into an Account.
   if (isDeposit)
   {
      // This block returns an error message if the amount is negative.
      if (amount < 0)
      {
         cout << "Amount cannot be negative, deposit not executed" << endl;
         return;
      }

      // This block deposits into the Account and outputs the success message.
      arr[index]->deposit(amount, d);
      cout << "Deposit executed: ";
      arr[index]->print();
   }
   // This block represents the user's choice to withdraw from an Account.
   else
   {
      // This block returns an error message if the amount is negative.
      if (amount < 0)
      {
         cout << "Amount cannot be negative, withdraw not executed" << endl;
         return;
      }
      // This block returns an error message if the withdraw amount exceeds the allowed withdraw amount based on the current balance.
      else if (!arr[index]->withdraw(amount, d))
      {
         cout << "Insufficient balance, withdrawal not executed" << endl;
         return;
      }

      // This block outputs the success message.
      cout << "Withdraw executed: ";
      arr[index]->print();
   }
}

// This function represents the user's choice to print the information for all Accounts.
void printAccounts(Account *arr[], int size)
{
   cout << "Accounts" << endl << "========" << endl;

   // This block loops through the Account array and outputs its information as long as it's not an empty element within the array.
   for (int i = 0; i < size; i++)
      if (arr[i] != nullptr)
         arr[i]->print();
}
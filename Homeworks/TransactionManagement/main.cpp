/*
 * Program Name: Homework 7, Section 1.10 - Bank Transaction Management
 * Author: Viet Vu
 * Date: April 3, 2022
 * Program Description: This program is designed to allow users to create multi-owner bank accounts and withdraw and
 *                      deposit money according to some specifications. This program also utilizes OOP to function.
 */

#include <iostream>
#include <iomanip>
#include "Account.h"

using namespace std;

// These are the function prototypes. They generally appear in the order in which they appear.
int getMenuChoice();
void createAccount();
void withdrawDeposit(string);
void displayAccounts();

// These are the global int variables and arrays as required by ZyBooks.
const int MAX_NUM_ACCOUNTS = 4;
Account *accountArray[MAX_NUM_ACCOUNTS];

// This is the main function. It generally follows the guidelines set by ZyBooks.
int main()
{
   // This loop sets all of the elements in the account array to nullptr.
   for (int i = 0; i < MAX_NUM_ACCOUNTS; i++)
      accountArray[i] = nullptr;

   // This block loops the user's menu of choices until they input '8', which would then terminate the program.
   int menuChoice = getMenuChoice();
   while (menuChoice != 8)
   {
      // These next cases are based on the menuChoice variable and represent valid menu choices.
      if (menuChoice == 1)
         createAccount();
      else if (menuChoice == 2)
         withdrawDeposit("deposit");
      else if (menuChoice == 3)
         withdrawDeposit("withdraw");
      else if (menuChoice == 4)
         displayAccounts();
      // This case represents the placeholder for the extra credit options.
      else if (menuChoice == 5 || menuChoice == 6 || menuChoice == 7)
         break;
      // This line regathers the user's menu choice.
      menuChoice = getMenuChoice();
   }

   return 0;
}

// This function displays the user's menu of choices and gathers their menu choice.
int getMenuChoice()
{
   // This block outputs the user's menu of choices.
   cout << "Menu" << endl << "----" << endl;
   cout << "1->Create account 2->Deposit   3->Withdraw     4->Display " << endl;
   cout << "5->Delete owner   6->Add owner 7->Delete accnt 8->Quit    " << endl;

   // This block gathers the user's menu choice.
   int menuChoice;
   cin >> menuChoice;

   return menuChoice;
}

// This function represents the user's choice to create a new account.
void createAccount()
{
   // This block finds the first available, non-nullptr index.
   int index = 0;
   for (; index < MAX_NUM_ACCOUNTS; index++)
      if (accountArray[index] == nullptr)
         break;

   // This block tests if index is 4 (therefore index not found) and outputs corresponding the error message.
   if (index == 4)
   {
      cout << "Max number of accounts reached, cannot add a new account" << endl;
      return;
   }

   // This block gathers the user's number of owners for the current Account.
   int ownerNum;
   cout << "Enter number of owners: ";
   cin >> ownerNum;

   // This block gathers the user's account balance for the current Account.
   double amount;
   cout << "Enter amount: ";
   cin >> amount;

   // This line creates a new Account object with the newly inputted data.
   Account *accPtr = new Account(ownerNum, amount);
   cin.ignore();

   // This block gathers each owner's information.
   for (int i = 0; i < ownerNum; i++)
   {
      // This block gathers the current owner's name.
      string ownerName;
      cout << "Enter owner's name: ";
      getline(cin, ownerName);

      // This block gathers the current owner's date of birth.
      string ownerDOB;
      cout << "Enter owner's DOB, month, day then year: ";
      getline(cin, ownerDOB);

      // This block splits up the user's date of birth string into its respective month, day, and year components.
      // This block uses stringstreams, since standard string arrays were giving errors on ZyBooks.
      string month, day, year;
      stringstream inputStream(ownerDOB);
      inputStream >> month >> day >> year;
      Date DOB = {stoi(month), stoi(day), stoi(year)};

      // This block gathers the current owner's address.
      string ownerAddress;
      cout << "Enter owner's address: ";
      getline(cin, ownerAddress);

      // This block creates a new Person object with the newly inputted data and assigns the Person to the Account ptr from before.
      Person owner = {ownerName, DOB, ownerAddress};
      accPtr->setOwner(i, owner);
   }

   // This block adds the account to the account array and outputs that the account was created.
   accountArray[index] = accPtr;
   cout << "Account #" << accPtr->getAccountNumber() << " created" << endl;
}

// This function represents the user's choice to either withdraw or deposit to and from a given account.
// This function uses the type string to differentiate between withdrawing and depositing.
void withdrawDeposit(string type)
{
   // This block gathers the account number whose balance that the user wishes to manipulate.
   int accountNum;
   cout << "Enter account number: ";
   cin >> accountNum;

   // This block searches the account array for the given account num.
   int index = 0;
   for (; index < MAX_NUM_ACCOUNTS; index++)
      // This case terminates the loop early if the account array is not full.
      if (accountArray[index] == nullptr)
         index = 5;
      else if (accountArray[index]->getAccountNumber() == accountNum)
         break;

   // This block detects if the index is at least 4 (therefore index not found) and outputs the corresponding error message.
   if (index >= 4)
   {
      cout << "No such account" << endl;
      return;
   }

   // This block gathers the amount that the user wishes to deposit or withdraw from the account.
   double amount;
   cout << "Enter amount: ";
   cin >> amount;

   // This block represents the user's choice to deposit to the account.
   if (type == "deposit")
   {
      // This block detects if the amount is less than 0 and outputs the corresponding error message.
      if (amount < 0)
      {
         cout << "Amount cannot be negative, deposit not executed" << endl;
         return;
      }
      // This line deposits to the given amount to the found account.
      accountArray[index]->deposit(amount);
   }
   // This block represents the user's choice to withdraw from the account.
   else if (type == "withdraw")
   {
      // This block detects if the amount is less than 0 and outputs the corresponding error message.
      if (amount < 0)
      {
         cout << "Amount cannot be negative, withdrawal not executed" << endl;
         return;
      }
      // This block detects if the amount is greater than the existing balance and outputs the corresponding error message.
      else if (amount > accountArray[index]->getBalance())
      {
         cout << "Insufficient balance, withdrawal not executed" << endl;
         return;
      }
      // This line withdraws from the given amount to the found account.
      accountArray[index]->withdraw(amount);
   }
   // This line outputs the new balance amount.
   cout << "New balance is $" << fixed << setprecision(2) << accountArray[index]->getBalance() << endl;
}

// This function represents the user's choice to display all filled accounts.
void displayAccounts()
{
   // This line loops through the entire account array.
   for (int i = 0; i < MAX_NUM_ACCOUNTS; i++)
   {
      // This line ensures that the current array is not an empty account.
      if (accountArray[i] != nullptr)
      {
         // This line outputs the current account number.
         cout << "Account Number: " << accountArray[i]->getAccountNumber() << endl << "--------------" << endl;
         // This block loops through every owner and their respective information.
         for (int j = 0; j < accountArray[i]->getNumOwners(); j++)
            cout << "*Name: " << accountArray[i]->getOwner(j).name << ", " <<
                 "DOB: " << accountArray[i]->getOwner(j).DOB.month << "/" << accountArray[i]->getOwner(j).DOB.day << "/"
                 << accountArray[i]->getOwner(j).DOB.year << endl <<
                 "Address: " << accountArray[i]->getOwner(j).address << endl;
         // This line outputs the current balance of the current account.
         cout << "*Balance: $" << fixed << setprecision(2) << accountArray[i]->getBalance() << " " << endl;
      }
   }
}
// Program Name: Homework 5 - Section 1.8, Bank Account Management
// Author: Viet Vu
// Date: March 21, 2022
// Program Description: This program is designed to use structures and dynamic array allocation to manage the
//                      data of multiple bank accounts.

#include <iostream>

using namespace std;

// These structures are the ones required by ZyBooks.
struct Person
{
   string name;
   string address;
};

struct Account
{
   int accountNumber;
   Person ownerInfo;
   double balance;
};

// These are the function prototypes.
int processErrors(int&, bool);
bool validateInt(string);
bool validateDouble(string);
int getMenuChoice();
bool isDuplicate(Account*, int, int);
void populateAccount(Account*, int&, int);
void printAccount(const Account &acc);
void displayData(Account*, int&, int);

// This is the main function. It generally follows the outline set by ZyBooks.
int main()
{
   // This block prompts the user for their max number of bank accounts.
   string numAccounts;
   cout << "Enter max number of accounts: ";
   getline(cin, numAccounts);

   // This block allows the user up to 4 attempts to input an integer above 0 until the program terminates.
   int errorCount = 0;
   while (!validateInt(numAccounts))
   {
      if (processErrors(errorCount, true) == -1)
         return -1;
      getline(cin, numAccounts);
   }

   // This block creates a dynamically allocated array with the now-determined size value.
   int size = stoi(numAccounts);
   Account *accPtr = new Account[size];

   // This block is the main processing of the program. It is based off of the menu of choices.
   // This block uses -1 values to terminate the program early.
   int index = 0;
   while (true)
   {
      // This block gathers the user's menu choice for the program to later use.
      int menuChoice = getMenuChoice();
      if (menuChoice == -1)
         return -1;

      // This block represents the user's choice to enter data for a specific account.
      if (menuChoice == 1)
      {
         populateAccount(accPtr, index, size);
         if (index == -1)
            return -1;
      }
      // This block represents the user's choice to display data for a specific account.
      else if (menuChoice == 2)
      {
         int valid = 0;
         displayData(accPtr, valid, size);
         if (valid == -1)
            return -1;
      }
      // This block represents the user's choice to display data for all accounts.
      else if (menuChoice == 3)
      {
         for (int i = 0; i < size; i++)
            if (accPtr[i].balance != 0)
               printAccount(accPtr[i]);
      }
      // This block represents the user's choice to quit the program.
      else if (menuChoice == 4)
         break;
   }

   delete[] accPtr;
   return 0;
}

// This function represents the recurring output found across many of the program's conditions.
int processErrors(int &errorCount, bool isVal)
{
   // This block represents the case where a user inputs too many consecutive errors.
   // This block returns -1, where its connected functions are made to terminate the program if that is the case.
   errorCount++;
   if (errorCount > 4)
   {
      cout << "Too many unsuccessful attempts, exiting";
      return -1;
   }

   // This block represents the unique cases of when the output wants to differentiate between "value" and "choice".
   if (isVal)
      cout << "Invalid value, please reenter: ";
   else
      cout << "Invalid choice, please reenter: ";

   return 0;
}

// This function validates if a given string is an int greater than 0.
bool validateInt(string num)
{
   // This block loops throughout the string and makes sure that each character is a digit.
   for (int i = 0; i < num.length(); i++)
      if (!isdigit(num[i]))
         return false;

   // This block converts the string to an int and ensures that it is above 0.
   int numInt = stoi(num);
   if (numInt <= 0)
      return false;
   return true;
}

// This function validates if a given string is a double with no more than two decimals or decimal places.
bool validateDouble(string num)
{
   // This block loops through the string and ensures that it meets the proper requirements.
   int dotCount = 0;
   for (int i = 0; i < num.length(); i++)
   {
      // This block ensures that the string only contains digits and decimals.
      if (!isdigit(num[i]) && num[i] != '.')
         return false;
      // This block ensures that if the current spot is a decimal, then it is found no more than 2 spaces from the end of the string.
      if (num[i] == '.')
      {
         if (i + 3 < num.length())
            return false;
         dotCount++;
      }
   }

   // This block returns false if the decimal count exceeds 1; true if every test is passed.
   if (dotCount > 1)
      return false;
   return true;
}

// This function displays and gathers the user's menu choice and provides validation tests.
int getMenuChoice()
{
   // This block outputs the user's menu of choices.
   cout << endl << "Menu:" << endl;
   cout << "1->Enter data for specific account, 2->Display data for specific account" << endl << "3->Display data for all accounts  , 4->Quit:" << endl;

   // This block stores the user's choice.
   string menuChoice;
   getline(cin, menuChoice);

   // This block allows the user up to 4 attempts to input an integer above 0 until the program terminates.
   int errorCount = 0;
   while (!validateInt(menuChoice))
   {
      if (processErrors(errorCount, false) == -1)
         return -1;
      getline(cin, menuChoice);
   }

   // This block converts the string to an int and validates if it is below 4.
   // This block adds to the same error count as the previous while loop.
   int num = stoi(menuChoice);
   while (num > 4)
   {
      if (processErrors(errorCount, false) == -1)
         return -1;
      getline(cin, menuChoice);
   }
   return num;
}

// This function is the extra credit function to determine if a given account number has a duplicate.
bool isDuplicate(Account *arr, int const accNum, int const size)
{
   // This block goes through the current array's account number values and tests if it matches the new account number.
   for (int i = 0; i < size; i++)
      if (arr[i].accountNumber == accNum)
         return true;
   return false;
}

// This function represents the user's choice to enter data for a specific account.
void populateAccount(Account *arr, int &numAcc, int const size)
{
   // This block terminates the function if the current index value is equal to the size of the array.
   if (numAcc >= size)
   {
      cout << "Cannot execute, array is full" << endl;
      return;
   }

   // This block gathers the user's account number.
   string accNum;
   cout << "Enter account number: ";
   getline(cin, accNum);

   // This block allows the user up to 4 attempts to input an integer above 0 until the program terminates.
   int errorCount = 0;
   while (!validateInt(accNum))
   {
      if (processErrors(errorCount, true) == -1)
      {
         numAcc = -1;
         return;
      }
      getline(cin, accNum);
   }

   // This block converts the account number to an int and tests if it is a duplicate account number.
   // If the account number passes all tests, then it is stored within the array.
   int accountNumber = stoi(accNum);
   if (isDuplicate(arr, accountNumber, size))
   {
      cout << "Duplicate account number";
      numAcc = -1;
      return;
   }
   arr[numAcc].accountNumber = accountNumber;

   // This block gathers the user's account balance.
   string balance;
   cout << "Enter balance: ";
   getline(cin, balance);

   // This block allows the user up to 4 attempts to input an integer above 0 until the program terminates.
   // If the account balance passes all tests, then it is stored within the array.
   errorCount = 0;
   while (!validateDouble(balance))
   {
      if (processErrors(errorCount, true) == -1)
      {
         numAcc = -1;
         return;
      }
      getline(cin, balance);
   }
   arr[numAcc].balance = stod(balance);

   // This block gathers the user's owner name and stores it within the array.
   cout << "Enter owner's name: ";
   getline(cin, arr[numAcc].ownerInfo.name);

   // This block gathers the user's owner address and stores it within the array.
   cout << "Enter owner's address: ";
   getline(cin, arr[numAcc].ownerInfo.address);

   numAcc++;
}

// This function prints the contents of a given structure value passed by reference.
void printAccount(const Account &acc)
{
   cout << "Account #: " << acc.accountNumber << endl;
   cout << "Owner's name: " << acc.ownerInfo.name << endl;
   cout << "Owner's address: " << acc.ownerInfo.address << endl;
   cout << "Balance: " << acc.balance << endl;
}

// This function represents the user's choice to display data for a specific account.
void displayData(Account *arr, int &valid, int const size)
{
   // This block gathers the user's account number that they wish to display.
   string accNum;
   cout << "Enter account number: ";
   getline(cin, accNum);

   // This block allows the user up to 4 attempts to input an integer above 0 until the program terminates.
   int errorCount = 0;
   while (!validateInt(accNum))
   {
      if (processErrors(errorCount, true) == -1)
      {
         valid = -1;
         return;
      }
      getline(cin, accNum);
   }

   // This block goes throughout the array and finds the index value where the account number is found.
   bool isFound = false;
   int index = 0;
   for (; index < size && !isFound; index++)
      if (stoi(accNum) == arr[index].accountNumber)
         isFound = true;
   index--;

   // This block outputs the corresponding output depending on if the account number was found.
   if (isFound)
      printAccount(arr[index]);
   else
      cout << "Account not found" << endl;
}
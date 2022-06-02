/*
 * Program Name: Homework 9, Section 1.12 - Transaction File Management
 * Author: Viet Vu
 * Date: April 15, 2022
 * Program Description: This program is designed to read a file and create account object each with their own unique
 *                      transactions and their various corresponding data.
 */

#include <iostream>
#include <fstream>
#include "Account.h"
#include "Date.h"

using namespace std;

// This block represents the function prototypes in the general order in which they appear.
int getAccountRecordNum(string fName);
int getMonthFromString(string d);
int getDayFromString(string d);
int getYearFromString(string d);
int getHourFromString(string d);
bool readAccounts(string fName, Account accntPtr[], int numAccnts);
void sortAccArr(Transaction transPtr[], int numTrans);
void displayOutput(Account accntPtr[], int numAccnts);

// This function is the main function. It generally follows the guidelines set by ZyBooks.
int main()
{
   // This block gathers the user's input file name.
   string fileName;
   cout << "Enter the account file name: ";
   cin >> fileName;

   // This block gathers the input file's number of records and outputs the result.
   int recordNum = getAccountRecordNum(fileName);
   cout << "There are " << recordNum << " accounts in the file" << endl << endl;

   // This line dynamically creates the array of Account objects using the number of records.
   Account *accArr = new Account[recordNum];
   // This line fills the contents of the Account array using the readAccounts function.
   readAccounts(fileName, accArr, recordNum);
   // This line displays the output using the contents of the Account array.
   displayOutput(accArr, recordNum);

   return 0;
}

// This function gathers the number of records found in the file by detecting the delimiter.
int getAccountRecordNum(string fName)
{
   // This line creates the input file with the given file name.
   ifstream inputFile(fName);

   // This block acts as input validation to see if the input file is able to be created.
   if (!inputFile)
      return -1;

   // This block runs throughout the file and counts every '#' delimiter found.
   int recordNum = 0;
   for (string readDelimiter; inputFile >> readDelimiter;)
      if (readDelimiter == "#")
         recordNum++;

   inputFile.close();
   return recordNum;
}

// This function gathers a month integer from a string.
int getMonthFromString(string d)
{
   string month = "";
   // This block builds up the month string up to the first '/' delimiter found.
   for (int i = 0; i < d.length(); i++)
      if (d[i] != '/')
         month += d[i];
      else
         break;

   return stoi(month);
}

// This function gathers a day integer from a string.
int getDayFromString(string d)
{
   string day = "";
   // This block builds up the day string between the first and second '/' delimiters found.
   for (int i = 0, count = 0; i < d.length(); i++)
      if ((count == 0) && (d[i] == '/'))
         count++;
      else if ((count == 1) && (d[i] != '/'))
         day += d[i];
      else if ((count == 1) && (d[i] == '/'))
         break;

   return stoi(day);
}

// This function gathers a year integer from a string.
int getYearFromString(string d)
{
   string year = "";
   // This block builds up the year string between the second and third '/' delimiters found.
   for (int i = 0, count = 0; i < d.length(); i++)
      if ((count < 2) && (d[i] == '/'))
         count++;
      else if ((count == 2) && (d[i] != '/'))
         year += d[i];
      else if ((count == 2) && (d[i] == '/'))
         break;

   return stoi(year);
}

// This function gathers an hour integer from a string.
int getHourFromString(string d)
{
   string hour = "";
   // This block builds up the hour string from the third '/' delimiter found until the end of the string.
   for (int i = 0, count = 0; i < d.length(); i++)
      if ((count < 3) && (d[i] == '/'))
         count++;
      else if ((count == 3) && (d[i] != '/'))
         hour += d[i];

   return stoi(hour);
}

// This function fills the Account array with the contents of the input file.
bool readAccounts(string fName, Account accntPtr[], int numAccnts)
{
   // This line creates the input file with the given file name.
   ifstream inputFile(fName);

   // This block acts as input validation to see if the input file is able to be created.
   if (!inputFile)
      return false;

   // This block loops for every Account.
   for (int i = 0; i < numAccnts; i++)
   {
      // This line creates a placeholder Account variable to be manipulated throughout this loop.
      Account acc;

      // This block reads the delimiter, number of accounts, and number of owners and sets it to the account's data accordingly.
      string delimiter; int accNum, ownerNum;
      inputFile >> delimiter >> accNum >> ownerNum;
      acc.setAccount(accNum, ownerNum);

      // This block loops for every owner of the current Account.
      for (int j = 0; j < ownerNum; j++)
      {
         // This block reads the name, owner's date of birth, and address.
         string name, DOB, address;
         inputFile >> name >> DOB >> address;

         // This block uses the corresponding get standalone functions to break up the DOB string into the proper variables.
         int month = getMonthFromString(DOB);
         int day = getDayFromString(DOB);
         int year = getYearFromString(DOB);
         int hour = getHourFromString(DOB);

         // This block creates a placeholder Date object and fills it with each date integer.
         Date ownerDOB;
         ownerDOB.set(month, day, year, hour);

         // This line creates a placeholder Person object with the contents of the owner's name, Date of birth, and owner address.
         Person owner = {name, ownerDOB, address};
         // This line assigns the placeholder Person object to the Account placeholder object.
         acc.setOwner(j, owner);
      }

      // This block reads the number of transactions for the current Account and assigns it accordingly.
      int transactionNum;
      inputFile >> transactionNum;
      acc.setNumTransactions(transactionNum);

      // This line creates a placeholder Transaction array to be filled throughout the following loop.
      Transaction *transArr = new Transaction[transactionNum];
      // This block loops for every transaction in the file.
      for (int j = 0; j < transactionNum; j++)
      {
         // This block reads the date, type, and amount of the current Transaction.
         string date; int type; double amount;
         inputFile >> date >> type >> amount;

         // This block uses the corresponding get standalone functions to break up the date string into the proper variables.
         int month = getMonthFromString(date);
         int day = getDayFromString(date);
         int year = getYearFromString(date);
         int hour = getHourFromString(date);

         // This block creates a placeholder Date object and fills it with each date integer.
         Date transactionDate;
         transactionDate.set(month, day, year, hour);

         Transaction traction = {transactionDate, type, amount};
         transArr[j] = traction;
      }
      // This line sorts the Transaction array for the extra credit portion of this assignment.
      sortAccArr(transArr, transactionNum);
      // This line assigns the Transaction array to the Account placeholder object.
      acc.setTransacPtr(transArr);

      // This line assigns the Account placeholder object to the primary Account array.
      accntPtr[i] = acc;
   }

   inputFile.close();
   return true;
}

// This function represents the extra credit portion of this assignment to sort each transaction by their dates.
// This function mimics the structure of the selection sort algorithm found in the textbook.
void sortAccArr(Transaction transPtr[], int numTrans)
{
   int minInd; Transaction minTransacton;
   for (int start = 0; start < (numTrans - 1); start++)
   {
      minInd = start;
      minTransacton = transPtr[start];

      for (int ind = (start + 1); ind < numTrans; ind++)
      {
         if (transPtr[ind].transactionDate < minTransacton.transactionDate)
         {
            minTransacton = transPtr[ind];
            minInd = ind;
         }
      }
      transPtr[minInd] = transPtr[start];
      transPtr[start] = minTransacton;
   }
}

// This function displays the contents of the Account array with the correct formatting.
void displayOutput(Account accntPtr[], int numAccnts)
{
   // This block loops for every Account.
   for (int i = 0; i < numAccnts; i++)
   {
      // This line outputs the account number.
      cout << endl << "Account Number: " << accntPtr[i].getAccountNumber() << endl << "===============" << endl;

      // This block loops for every owner of the current Account and outputs their name, DOB, and address.
      for (int j = 0; j < accntPtr[i].getNumOwners(); j++)
      {
         cout << "Name: " << accntPtr[i].getOwner(j).name << ", DOB: ";
         accntPtr[i].getOwner(j).DOB.print();
         cout << ", Address: " << accntPtr[i].getOwner(j).address << endl << endl;
      }

      // This line segments for the current Account's transaction history.
      cout << "Transaction history:" << endl << "--------------------";

      // This variable serves as a workaround to the issue in ZyBooks where the balance variable in Account is private with no accessor or mutator functions.
      double bal = 0;
      // This block loops for every transaction of the current Account.
      for (int j = 0; j < accntPtr[i].getNumTransactions(); j++)
      {
         // Ths block outputs the current transaction number and its corresponding date.
         cout << endl << "Transaction #" << (j + 1) << endl << "Date: ";
         accntPtr[i].getTransaction(j).transactionDate.print();

         // This block uses the Transaction's type variable to determine the type portion of the output and manipulates the balance accordingly.
         if (accntPtr[i].getTransaction(j).type == 1)
         {
            cout << ", type: account creation";
            bal += accntPtr[i].getTransaction(j).amount;
         }
         else if (accntPtr[i].getTransaction(j).type == 2)
         {
            cout << ", type: deposit";
            bal += accntPtr[i].getTransaction(j).amount;
         }
         else if (accntPtr[i].getTransaction(j).type == 3)
         {
            cout << ", type: withdrawal";
            bal -= accntPtr[i].getTransaction(j).amount;
         }
         // This line outputs the amount and the new balance of the current transaction.
         cout << ", amount: " << accntPtr[i].getTransaction(j).amount << ", new balance: " << bal << endl;
      }
   }
}
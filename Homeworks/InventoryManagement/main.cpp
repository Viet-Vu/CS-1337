// Program Name: Homework 6 - Section 1.9, Inventory Management with OOP
// Author: Viet Vu
// Date: March 26, 2022
// Program Description: This program is designed to manage an object array read from a file and manipulate its values using OOP.

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Product.h"

using namespace std;

// This structure is used to keep track of the details of every transaction for the extra credit assignments.
struct Transaction
{
   int transactionNum;
   string PLU;
   string type;
   int amount;
};

// These are the function prototypes in the order that they are used throughout the program.
int getFileSize(string);
void fillArray(Product*, string, int);
void printArray(Product*, int, int);
int getMenuChoice();
void addToInventory(Product*, int, Transaction*, int&);
void subtractFromInventory(Product*, int, Transaction*, int&);

// This function is the main function. It generally follows the guidelines set by ZyBooks.
int main()
{
   // This block prompts the user for their input file name.
   string fileName;
   cout << "Enter the file name: ";
   cin >> fileName;

   // This line stores the file size of the input file using a function.
   int fileSize = getFileSize(fileName);

   // This block terminates the program if the input file does not exist and outputs the number of records otherwise.
   if (fileSize == -1)
   {
      cout << "File " << fileName << " could not be opened" << endl;
      return -1;
   }
   cout << "There are " << fileSize << " records in the file" << endl << endl;

   // This block dynamically allocates the Product array with the file size and fills the array, and prints it using multiple functions.
   Product *arrPtr = new Product[fileSize];
   fillArray(arrPtr, fileName, fileSize);
   printArray(arrPtr, fileSize, 0);

   // This line dynamically allocates the Transaction array for the extra credit. This will hold the last 5 transactions that the user inputs.
   Transaction *arrPtr2 = new Transaction[5];
   // This block loops through the main part of the program until the user inputs 4. Each choice is represented by its respective function.
   int choice = getMenuChoice(), transactionNum = 0;
   while (choice != 4)
   {
      if (choice == 1)
         addToInventory(arrPtr, fileSize, arrPtr2, transactionNum);
      else if (choice == 2)
         subtractFromInventory(arrPtr, fileSize, arrPtr2, transactionNum);
      else if (choice == 3)
         printArray(arrPtr, fileSize, 1);
      // This line regathers the user's menu choice.
      choice = getMenuChoice();
   }

   // This block occurs whenever the user inputs 4, and it produces the user's list of transactions in the format of the extra credit requirements.
   cout << endl << "History of transactions" << endl << "-----------------------" << endl;
   for (int i = 0; (i < 5) && (arrPtr2[i].amount != 0); i++)
      cout << "Transaction #: " << arrPtr2[i].transactionNum << ", PLU: " << arrPtr2[i].PLU << ", type: " << arrPtr2[i].type << ", amount: " << arrPtr2[i].amount << endl;

   delete[] arrPtr;
   delete[] arrPtr2;
   return 0;
}

// This function gathers the file size of the input file.
int getFileSize(string fileName)
{
   // This block creates the input file and returns -1 if it cannot be opened.
   ifstream inputFile(fileName);
   if (!inputFile)
      return -1;

   // This block runs through the file and increases the fileSize value as it goes through each line.
   int fileSize;
   for (string doNothing; getline(inputFile, doNothing); fileSize++);

   inputFile.close();
   return fileSize;
}

// This function fills the Product array with the contents of the input file using the Product member functions.
void fillArray(Product *arr, string fileName, int fileSize)
{
   // This line creates the input file. No file validation is needed if it has reached this point of the program.
   ifstream inputFile(fileName);

   // This block reads the values of the input file and puts those values into the Product array in its corresponding components.
   string PLU, name;
   int type, inventory;
   double price;
   for (int i = 0; i < fileSize; i++)
   {
      inputFile >> PLU >> name >> type >> price >> inventory;
      arr[i].setProductAttributes(PLU, name, type, price, inventory);
   }
   inputFile.close();
}

// This function outputs the Product array in the required format.
void printArray(Product *arr, int fileSize, int type)
{
   // This block outputs a different title according to the type value supplied when calling this function.
   if (type == 0)
      cout << "Content of object array" << endl << "-----------------------" << endl;
   else if (type == 1)
      cout << "Current inventory" << endl << "-----------------" << endl;

   // This block outputs each line of the Product array in the format required by ZyBooks.
   for (int i = 0; i < fileSize; i++)
      cout << "PLU: " << arr[i].getPLU() << ", " << arr[i].getName() << setw(25 - arr[i].getName().length()) << ", type: " << arr[i].getType() << ", unit price: " << setw(5) << arr[i].getPrice() << ", inventory: " << arr[i].getInventory() << endl;
   cout << endl;
}

// This function outputs the user's menu of choices and gathers their choice.
int getMenuChoice()
{
   // This block outputs the user's menu of choices.
   cout << "Menu" << endl << "----" << endl;
   cout << "1->Add to inventory           , 2->Subtract from inventory" << endl;
   cout << "3->Print info for all products, 4->Exit" << endl;

   // This block gathers the user's menu choice.
   int choice;
   cin >> choice;

   return choice;
}

// This function represents the user's menu choice #1 to add a value to a given Product.
void addToInventory(Product *arr, int fileSize, Transaction *arr2, int &transactionNum)
{
   // This block prompts the user for which Product they wish to add to.
   string PLU;
   cout << "Enter the PLU: ";
   cin >> PLU;

   // This block finds the index value where the PLU is found in the Product array.
   int index = 0;
   bool isFound = false;
   for (; (index < fileSize) && (!isFound); index++)
      if (arr[index].getPLU() == PLU)
         isFound = true;
   index--;

   // This block outputs the error message and terminates this function if the PLU is not found.
   if (!isFound)
   {
      cout << "PLU not found" << endl << endl;
      return;
   }

   // This block prompts the user for the value that they wish to add to their Product.
   int amount;
   cout << "Enter amount to add: ";
   cin >> amount;

   // This block outputs the error message and terminates this function if the amount is invalid.
   if (amount <= 0)
   {
      cout << "Amount must be > 0" << endl << endl;
      return;
   }

   // This block updates the Product's inventory according to the user's amount.
   arr[index].setInventory(arr[index].getInventory() + amount);
   cout << endl;

   // This block shifts the Transaction array one down to make room for a new transaction.
   for (int i = 4; i > 0; i--)
      arr2[i] = arr2[i - 1];

   // This block records this transaction into the Transaction array.
   transactionNum++;
   arr2[0].transactionNum = transactionNum;
   arr2[0].PLU = PLU;
   arr2[0].type = "Add to inventory";
   arr2[0].amount = amount;
}

// This function represents the user's menu choice #2 to subtract a value from a given Product.
void subtractFromInventory(Product *arr, int fileSize, Transaction *arr2, int &transactionNum)
{
   // This block prompts the user for which Product they wish to subtract from.
   string PLU;
   cout << "Enter the PLU: ";
   cin >> PLU;

   // This block finds the index value where the PLU is found in the Product array.
   int index = 0;
   bool isFound = false;
   for (; (index < fileSize) && (!isFound); index++)
      if (arr[index].getPLU() == PLU)
         isFound = true;
   index--;

   // This block outputs the error message and terminates this function if the PLU is not found.
   if (!isFound)
   {
      cout << "PLU not found" << endl << endl;
      return;
   }

   // This block prompts the user for the value that they wish to subtract from their Product.
   int amount;
   cout << "Enter amount to subtract: ";
   cin >> amount;

   if (amount <= 0)
   {
      cout << "Amount must be > 0" << endl << endl;
      return;
   }

   // This block corrects the amount value if it exceeds the current inventory of the Product in question.
   if (amount > arr[index].getInventory())
      amount = arr[index].getInventory();

   // This block updates the Product's inventory according to the user's amount.
   arr[index].setInventory(arr[index].getInventory() - amount);
   cout << endl;

   // This block shifts the Transaction array one down to make room for a new transaction.
   for (int i = 4; i > 0; i--)
      arr2[i] = arr2[i - 1];

   // This block records this transaction into the Transaction array.
   transactionNum++;
   arr2[0].transactionNum = transactionNum;
   arr2[0].PLU = PLU;
   arr2[0].type = "Subtract from inventory";
   arr2[0].amount = amount;
}
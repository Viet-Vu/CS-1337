// Program Name: Homework 2: 1.5 Grocery Checkout-Inventory
// Author: Viet Vu
// Date: February 19, 2022

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// These are the function prototypes.
int getFileCount(string fileName);
bool readInventory(string fileName, int recordNum, string *pluArr, double *priceArr, string *productArr, int *typeArr, int *inventoryArr);
void displayInventory(int recordNum, string *pluArr, double *priceArr, string *productArr, int *typeArr, int *inventoryArr, int type);
double checkout(int recordNum, string *pluArr, double *priceArr, int *inventoryArr);

// This is the main function. It follows the requirements in order as set by the assignment.
int main()
{
   string fileName;
   int userChoice;

   // This block prompts the user for their file name and stores it in the "fileName" string.
   cout << "Enter the file name: ";
   cin >> fileName;

   // This block calls the "getFileCount" function to gather the number of items in the file and outputs the number.
   int fileCount = getFileCount(fileName);
   cout << "There are " << fileCount << " records in the file" << endl;

   // This block creates the dynamic memory arrays according to the now-determined file size.
   string *pluPtr = new string[fileCount];
   string *productPtr = new string[fileCount];
   int *typePtr = new int[fileCount];
   double *pricePtr = new double[fileCount];
   int *inventoryPtr = new int[fileCount];

   // This block calls readInventory to fill in the arrays and determines if the file is able to be opened.
   // This block also displays the file contents for the first time using the "displayInventory" function.
   if (!readInventory(fileName, fileCount, pluPtr, pricePtr, productPtr, typePtr, inventoryPtr))
      return -1;
   displayInventory(fileCount, pluPtr, pricePtr, productPtr, typePtr, inventoryPtr, 0);

   // This block outputs the user's menu of choices and stores their value inside the "userChoice" int.
   cout << "1 - Checkout" << endl << "2 - Print current inventory" << endl << "3 - Quit";
   cin >> userChoice;

   // This block loops so long as the user does not input 3 to exit the program.
   while (userChoice != 3)
   {
      // This block represents the user's choice to "Checkout" utilizing the "checkout" function.
      // This block also reprints the user's menu of choices.
      if (userChoice == 1)
      {
         checkout(fileCount, pluPtr, pricePtr, inventoryPtr);
         cout << "1 - Checkout" << endl << "2 - Print current inventory" << endl << "3 - Quit";
      }
      // This block represents the user's choice to "Print current inventory" utilizing the "displayInventory" function.
      // This block also reprints the user's menu of choices.
      else if (userChoice == 2)
      {
         displayInventory(fileCount, pluPtr, pricePtr, productPtr, typePtr, inventoryPtr, 1);
         cout << "1 - Checkout" << endl << "2 - Print current inventory" << endl << "3 - Quit";
      }
      // This block represents the case where the user inputs an invalid choice.
      // So long as the user provides an invalid choice, this portion will loop indefinitely.
      else
         cout << endl << "Invalid choice, reenter: ";
      cin >> userChoice;
   }

   // This block outputs the final inventory count of the file and represents the exiting phase.
   displayInventory(fileCount, pluPtr, pricePtr, productPtr, typePtr, inventoryPtr, 2);
   cout << "Exiting" << endl;

   // This block releases all of the dynamically allocated memory arrays.
   delete[] pluPtr;
   delete[] productPtr;
   delete[] typePtr;
   delete[] pricePtr;
   delete[] inventoryPtr;

   return 0;
}

// This function opens the input file to read the number of items and then closes the file.
// This function returns the number of items found in the input file.
int getFileCount(string fileName)
{
   string doNothing;
   int itemCount;

   // This block creates the input file and returns 0 if it cannot be opened.
   ifstream inputFile(fileName);
   if (!inputFile)
      return 0;

   // This block runs through the input file and counts the number of lines.
   while (getline(inputFile, doNothing))
   {
      // This if statement corrects the spacing error found inside of the "productData3.txt" file.
      if (doNothing == "")
         break;
      itemCount++;
   }
   inputFile.close();

   return itemCount;
}

// This function fills in the arrays according to the contents of the file.
// This function returns true if the file can be opened, false otherwise.
bool readInventory(string fileName, int recordNum, string *pluArr, double *priceArr, string *productArr, int *typeArr, int *inventoryArr)
{
   // This block creates the input file and returns false if it cannot be opened.
   ifstream inputFile(fileName);
   if (!inputFile)
      return false;

   // This block fills in the corresponding arrays with the contents of the file.
   for (int i = 0; inputFile >> pluArr[i]; i++)
      inputFile >> productArr[i] >> typeArr[i] >> priceArr[i] >> inventoryArr[i];
   inputFile.close();

   return true;
}

// This function displays the data stored in the arrays in the required format.
void displayInventory(int recordNum, string *pluArr, double *priceArr, string *productArr, int *typeArr, int *inventoryArr, int type)
{
   // This block creates the appropriate title depending on when this function is called, determined by the "type" parameter.
   if (type == 0)
      cout << endl << "Inventory read from file" << endl << "------------------------" << endl;
   else if (type == 1)
      cout << endl << "Current inventory" << endl << "-----------------" << endl;
   else
      cout << endl << "Updated inventory" << endl << "-----------------" << endl;

   // This block outputs each line of the arrays in the required format.
   for (int i = 0; i < recordNum; i++)
      cout << "PLU: " << pluArr[i] << ", " << productArr[i] << setw(25 - productArr[i].length()) << ", type: " << typeArr[i] << ", unit price: " << setw(5) << priceArr[i] << ", inventory: " << inventoryArr[i] << endl;
}

// This function gathers the user's checkout options and updates the inventory array accordingly.
// This function returns the total dollar value spent by the user.
double checkout(int recordNum, string *pluArr, double *priceArr, int *inventoryArr)
{
   string userPlu;
   int userQuantity;
   double total;

   // This block gathers the user's PLU name and stores it inside of the "userPlu" string.
   cout << endl << "Enter PLU, 0 if done: ";
   cin >> userPlu;

   // This block loops the user's options so long as they do not provide "0" for their "userPlu", which represents an exit.
   while (userPlu != "0")
   {
      // This block prompts the user for the quantity that they desire for their PLU and stores it inside of the "userQuantity" int.
      cout << "Enter quantity: ";
      cin >> userQuantity;

      // This block asks the user for a positive "userQuantity" until they provide a positive value.
      while (userQuantity < 1)
      {
         cout << "Quantity must be positive, reenter: ";
         cin >> userQuantity;
      }

      int index = -1;

      // This block finds the index value that the user's PLU is found at.
      for (int i = 0; i < recordNum; i++)
         if (pluArr[i] == userPlu)
            index = i;

      // This block outputs if the PLU is unable to be found, the user will then be able to reenter a PLU value.
      if (index == -1)
         cout << "PLU not found" << endl;
      // This block updates the inventory array and total price according to the user's input data.
      else
      {
         // This block corrects the user's quantity value if it is above the leftover inventory.
         if (userQuantity >= inventoryArr[index])
            userQuantity = inventoryArr[index];

         // This block updates the inventory array and the total price according to the user's input data.
         inventoryArr[index] -= userQuantity;
         total += (priceArr[index] * userQuantity);
      }

      cout << endl << "Enter PLU, 0 if done: ";
      cin >> userPlu;
   }
   // This block outputs the total value of the user's purchase.
   cout << "Total is: $" << total << endl << endl;

   return total;
}
// Program Name: Homework 1: 1.4 Searching and Sorting Algorithms
// Author: Viet Vu
// Date: February 09, 2022

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// These are the function prototypes.
int readInputFile(int netID[], string major[], double GPA[]);
void modifiedSortGPA(double array1[], int array2[], string array3[], int size);
void modifiedSortID(int array2[], double array1[], string array3[], int size);
int linearSearchID(int arr[], int numElems, int value, int &nIter);
int binarySearchID(int arr[], int numElems, int value, int &nIter);
void displayArrays(int array1[], double array2[], string array3[], int inputFileSize, int type);
int displayMenu();
void listTopN(int array1[], double array2[], string array3[]);
void searchNetID(int array1[], double array2[], int size);

const int NUM_ELMTS = 18;

// This is the main function.
int main()
{
   // These are the base arrays that are to be filled from the contents of the input file.
   int netID[NUM_ELMTS];
   string major[NUM_ELMTS];
   double GPA[NUM_ELMTS];

   // These are the arrays to be sorted from the base arrays based on GPA.
   double sortedGPAbyGPA[NUM_ELMTS];
   int sortedNetIDbyGPA[NUM_ELMTS];
   string sortedMajorbyGPA[NUM_ELMTS];

   // These are the arrays to be sorted from the base arrays based on netID.
   int sortedNetIDbyID[NUM_ELMTS];
   string sortedMajorbyID[NUM_ELMTS];
   double sortedGPAbyID[NUM_ELMTS];

   // This block calls the readInputFile function to ask the user for their input file and fill the base arrays.
   // This block returns exit failure if the file cannot be opened.
   int inputFileSize = readInputFile(netID, major, GPA);
   if (inputFileSize == -1)
      return -1;

   // This block copies the data from the base arrays to the GPA arrays.
   // This block then uses the modifiedSortGPA function to sort the GPA arrays.
   for (int i = 0; i < inputFileSize; i++)
   {
      sortedGPAbyGPA[i] = GPA[i];
      sortedNetIDbyGPA[i] = netID[i];
      sortedMajorbyGPA[i] = major[i];
   }
   modifiedSortGPA(sortedGPAbyGPA, sortedNetIDbyGPA, sortedMajorbyGPA, inputFileSize);

   // This block copies the data from the base arrays to the netID arrays.
   // This block then uses the modifiedSortID function to sort the netID arrays.
   for (int i = 0; i < inputFileSize; i++)
   {
      sortedNetIDbyID[i] = netID[i];
      sortedMajorbyID[i] = major[i];
      sortedGPAbyID[i] = GPA[i];
   }
   modifiedSortID(sortedNetIDbyID, sortedGPAbyID, sortedMajorbyID, inputFileSize);

   // This block displays the three arrays with the proper formatting.
   displayArrays(netID, GPA, major, inputFileSize, 1);
   displayArrays(sortedNetIDbyGPA, sortedGPAbyGPA, sortedMajorbyGPA, inputFileSize, 2);
   displayArrays(sortedNetIDbyID, sortedGPAbyID, sortedMajorbyID, inputFileSize, 3);

   // This block produces the player's choice menu with the displayMenu function and gathers the user's choice.
   // This block then calls the listTopN or searchNetID functions or returns exit failure accordingly.
   // This block also loops so long as the user provides valid inputs or does not exit.
   int choice = displayMenu();
   while (choice == 1 || choice == 2)
   {
      if (choice == 1)
         listTopN(sortedNetIDbyGPA, sortedGPAbyGPA, sortedMajorbyGPA);
      else if (choice == 2)
         searchNetID(sortedNetIDbyID, sortedGPAbyID, inputFileSize);

      choice = displayMenu();
   }
   if (choice == 3)
      return -1;

   return 0;
}

// This function gathers the user's input for their file name and fills the base arrays.
int readInputFile(int netID[], string major[], double GPA[])
{
   // This block takes in the user's file name.
   string inputFileName;
   cout << "Enter file name: ";
   cin >> inputFileName;

   // This block creates the input file and determines if it cannot be opened.
   ifstream inputFile(inputFileName);
   if (!inputFile)
   {
      cout << "Could not open file" << endl << "Exiting" << endl;
      return -1;
   }

   // This block fills in the base arrays with the contents of the input file.
   int size = 0;
   for (; inputFile >> netID[size]; size++)
      inputFile >> major[size] >> GPA[size];

   inputFile.close();
   return size;
}

// This function sorts the GPA arrays in a paralleled structure based on the GPA values.
void modifiedSortGPA(double array1[], int array2[], string array3[], int size)
{
   int minInd, minVal2;
   double minVal1;
   string minVal3;

   // This block mimics the sorting algorithm from our textbook, except now expanded to three arrays.
   for (int i = 0; i < (size - 1); i++)
   {
      minInd = i;

      minVal1 = array1[i];
      minVal2 = array2[i];
      minVal3 = array3[i];

      for (int j = (i + 1); j < size; j++)
      {
         if (array1[j] < minVal1)
         {
            minVal1 = array1[j];
            minVal2 = array2[j];
            minVal3 = array3[j];

            minInd = j;
         }
      }
      array1[minInd] = array1[i];
      array2[minInd] = array2[i];
      array3[minInd] = array3[i];

      array1[i] = minVal1;
      array2[i] = minVal2;
      array3[i] = minVal3;
   }
}

// This function sorts the netID arrays in a paralleled structure based on the netID values.
void modifiedSortID(int array2[], double array1[], string array3[], int size)
{
   int minInd, minVal2;
   double minVal1;
   string minVal3;

   // This block mimics the sorting algorithm from our textbook, except now expanded to three arrays.
   for (int i = 0; i < (size - 1); i++)
   {
      minInd = i;

      minVal1 = array1[i];
      minVal2 = array2[i];
      minVal3 = array3[i];

      for (int j = (i + 1); j < size; j++)
      {
         if (array2[j] < minVal2)
         {
            minVal1 = array1[j];
            minVal2 = array2[j];
            minVal3 = array3[j];

            minInd = j;
         }
      }
      array1[minInd] = array1[i];
      array2[minInd] = array2[i];
      array3[minInd] = array3[i];

      array1[i] = minVal1;
      array2[i] = minVal2;
      array3[i] = minVal3;
   }
}

// This function linear searches through a given array for a given value.
int linearSearchID(int arr[], int numElems, int value, int &nIter)
{
   int ind = 0, pos = -1;
   bool notFound = true;
   nIter = 0;

   // This block mimics the linear search algorithm from our textbook, except now keeping track of the iterations.
   while (ind < numElems && notFound)
   {
      if (arr[ind] == value)
      {
         notFound = false;
         pos = ind;
      }
      ind++;
      nIter++;
   }
   return pos;
}

// This function binary searches through a given array for a given value.
int binarySearchID(int arr[], int numElems, int value, int &nIter)
{
   int first = 0, last = numElems - 1, pos = -1, middle;
   bool notFound = true;
   nIter = 0;

   // This block mimics the binary search algorithm from our textbook, except now keeping track of the iterations.
   while (first <= last && notFound)
   {
      middle = (first + last) / 2;

      if (arr[middle] < value)
         first = middle + 1;
      else if (arr[middle] > value)
         last = middle - 1;
      else
      {
         notFound = false;
         pos = middle;
      }
      nIter++;
   }
   return pos;
}

// This function displays a given array in the required format.
void displayArrays(int array1[], double array2[], string array3[], int inputFileSize, int type)
{
   // This block varies the title block depending on the 'type' value in the function call.
   if (type == 1)
      cout << "Original arrays:" << endl << "----------------" << endl;
   else if (type == 2)
      cout << "Arrays sorted by GPA:" << endl << "---------------------" << endl;
   else
      cout << "Arrays sorted by netID:" << endl << "-----------------------" << endl;

   // This block sets up the table with the appropriate spacing based on the values of the given arrays.
   cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;
   for (int i = 0; i < inputFileSize; i++)
      if (i % 2 == 0)
         cout << setw(5) << i << setw(7) << array1[i] << setw(7) << array3[i] << setw(6) << fixed << setprecision(2) << array2[i];
      else
         cout << setw(8) << i << setw(7) << array1[i] << setw(7) << array3[i] << setw(6) << fixed << setprecision(2) << array2[i] << endl;
   cout << endl;
}

// This function displays the user's menu once they input their input file.
int displayMenu()
{
   int choice;

   // This block outputs the title and choices for the user to pick between.
   cout << "***************" << endl << "Menu of choices" << endl << "***************" << endl;
   cout << "1 - List top n students" << endl << "2 - Search on a netID" << endl << "3 - Quit" << endl;
   cin >> choice;

   // This block produces the exiting message for if the user chooses to exit.
   if (choice == 3)
      cout << "Exiting" << endl;

   return choice;
}

// This function lists the top n students from the GPA arrays based on their GPAs.
void listTopN(int array1[], double array2[], string array3[])
{
   // This block gathers the user's n values for their top n list.
   int n;
   cout << "Enter n: ";
   cin >> n;

   // This block limits the n value to 10.
   if (n >= 10)
      n = 10;

   // This block outputs the top n students in the required format.
   cout << "Top " << n << " students are:" << endl << endl;
   for (int i = n - 1; i >= 0; i--)
      cout << "netID: " << array1[i] << ", major: " << array3[i] << ", GPA: " << fixed << setprecision(2) << array2[i] << endl;
   cout << endl;
}

// This function represents the process for when the user wishes to search on a netID from the menu.
void searchNetID(int array1[], double array2[], int size)
{
   // This block gathers the user's netID that they wish to search for.
   int netID;
   cout << "Enter netID: ";
   cin >> netID;
   cout << endl;

   // This block calls the linearSearchID function to produce the linear search results of the requested netID.
   int iterations;
   int index = linearSearchID(array1, size, netID, iterations);
   cout << "Result of linear search:" << endl << "------------------------" << endl;
   if (index != -1)
   {
      cout << "Student found at index " << index << ", GPA is " << fixed << setprecision(2) << array2[index] << endl;
      cout << "It took " << iterations << " iterations" << endl << endl;
   }
   else
   {
      cout << "Student not found" << endl;
      cout << "It took " << iterations << " iterations" << endl << endl;
   }

   // This block calls the binarySearchID function to produce the binary search results of the requested netID.
   index = binarySearchID(array1, size, netID, iterations);
   cout << "Result of binary search:" << endl << "------------------------" << endl;
   if (index != -1)
   {
      cout << "Student found at index " << index << ", GPA is " << fixed << setprecision(2) << array2[index] << endl;
      cout << "It took " << iterations << " iterations" << endl << endl;
   }
   else
   {
      cout << "Student not found" << endl;
      cout << "It took " << iterations << " iterations" << endl << endl;
   }
}
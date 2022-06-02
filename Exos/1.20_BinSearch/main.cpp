#include <iostream>
#include <iomanip>

using namespace std;

int linSearch(int arr[], int size, int searchVal);
int binSearch(int arr[], int size, int searchVal);

const int ARR_SIZE = 10;

int main()
{
   int arr[ARR_SIZE] = {1, 5, 8, 2, 6, 7, 9, 45, 22, 12};
   int sortedArr[ARR_SIZE] = {1, 2, 5, 6, 7, 8, 9, 12, 22, 45};
   int val;

   cout << "Array: " << endl;
   for (int i = 0; i < ARR_SIZE; i++)
   {
      cout << setw(6) << arr[i];
      if ((i + 1) % 5 == 0)
         cout << endl;
   }

   cout << "Sorted array: " << endl;
   for (int i = 0; i < ARR_SIZE; i++)
   {
      cout << setw(6) << sortedArr[i];
      if ((i + 1) % 5 == 0)
         cout << endl;
   }

   cout << "Enter search value:";
   cin >> val;

   cout << "Position in array is " << linSearch(arr, ARR_SIZE, val) << endl;
   cout << "Position in sorted array is " << binSearch(sortedArr, ARR_SIZE, val) << endl;

   return 0;
}

int linSearch(int arr[], int size, int searchVal)
{
   int ind = 0, pos = -1;
   bool notFound = true;

   while (ind < size && notFound)
   {
      if (arr[ind] == searchVal)
      {
         notFound = false;
         pos = ind;
      }
      ind++;
   }
   return pos;
}

int binSearch(int arr[], int size, int searchVal)
{
   int first = 0, last = size - 1, pos = -1, middle;
   bool notFound = true;

   while (first <= last && notFound)
   {
      middle = (first + last) / 2;
      if (arr[middle] < searchVal)
         first = middle + 1;
      else if (arr[middle] > searchVal)
         last = middle - 1;
      else
      {
         notFound = false;
         pos = middle;
      }
   }
   return pos;
}

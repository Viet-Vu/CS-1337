#include <iostream>
#include <iomanip>

using namespace std;

int linSearch(int arr[], int size, int searchVal);

const int ARR_SIZE = 10;

int main()
{
   int arr[ARR_SIZE] = {1, 5, 8, 2, 6, 7, 9, 45, 22, 12};
   int val;

   cout << "Array: " << endl;
   for (int i = 0; i < ARR_SIZE; i++)
   {
      cout << setw(6) << arr[i];
      if ((i + 1) % 5 == 0)
         cout << endl;
   }
   cout << "Enter search value:";
   cin >> val;
   cout << "Position in array is " << linSearch(arr, ARR_SIZE, val) << endl;

   return 0;
}

int linSearch(int arr[], int size, int searchVal)
{
   int ind = 0, position = -1;
   bool notFound = true;

   while (ind < size && notFound)
   {
      if (arr[ind] == searchVal)
      {
         notFound = false;
         position = ind;
      }
      ind++;
   }
   return position;
}
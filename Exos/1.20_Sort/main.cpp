#include <iostream>
#include <iomanip>

using namespace std;

void selectionSort(int arr[], int size);

const int ARR_SIZE = 50;

int main()
{
   int arr[ARR_SIZE];

   for (int i = 0; i < ARR_SIZE; i++)
      arr[i] = rand();

   cout << "Array: " << endl;
   for (int i = 0; i < ARR_SIZE; i++)
   {
      cout << setw(12) << arr[i];
      if ((i + 1) % 4 == 0)
         cout << endl;
   }

   selectionSort(arr, ARR_SIZE);

   cout << endl << "Sorted array: " << endl;
   for (int i = 0; i < ARR_SIZE; i++)
   {
      cout << setw(12) << arr[i];
      if ((i + 1) % 4 == 0)
         cout << endl;
   }
   return 0;
}

void selectionSort(int arr[], int size)
{
   int start, minInd, minVal;

   for (int start = 0; start < (size - 1); start++)
   {
      minInd = start;
      minVal = arr[start];

      for (int ind = (start + 1); ind < size; ind++)
      {
         if (arr[ind] < minVal)
         {
            minVal = arr[ind];
            minInd = ind;
         }
      }
      arr[minInd] = arr[start];
      arr[start] = minVal;
   }
}
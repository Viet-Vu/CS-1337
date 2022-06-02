/*
 * To initialize a 2D array with a list, you can use 1D lists,
 * one for each row, separated by commas, grouped inside outer
 * braces.
 *
 * Initialization is done row by row.
 *
 * When a 2D array is a function argument, the array name (address
 * of the array) is passed to the function.
 * The number of columns (2nd dimension) must always be provided in
 * the function prototype and the function header.
 * If the function needs to know the number of rows, it must
 * be provided as an additional argument.
 */

#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_STUDENTS = 4, NUM_TESTS = 3;

void print2DArray(double arr[][NUM_TESTS], int numRows);

int main()
{
   double score[NUM_STUDENTS][NUM_TESTS] =
   {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}, {100, 110, 120}};

   cout << "Content of score array" << endl;
   print2DArray(score, NUM_STUDENTS);

   return 0;
}

void print2DArray(double arr[][NUM_TESTS], int numRows)
{
   for (int row = 0; row < numRows; row++)
   {
      for (int col = 0; col < NUM_TESTS; col++)
         cout << setw(7) << arr[row][col];
      cout << endl;
   }
}
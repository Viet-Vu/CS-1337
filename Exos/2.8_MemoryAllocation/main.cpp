/*
 * With dynamic memory allocation, a program, during execution,
 * can request a chunk of memory large enough to hold a variable
 * or an array of a specific type.
 *
 * The computer gives the address of the chunk.
 * Our program needs a pointer to save the address.
 *
 * Useful for when we don't know how much memory we need
 * when we write the source code.
 *
 * When we are done with the memory, we should release it.
 * using "delete".
 */

#include <iostream>

using namespace std;

int main()
{
   int numTests;

   cout << "Enter the number of tests: ";
   cin >> numTests;

   double *testPtr = new double[numTests];

   for (int i = 0; i < numTests; i++)
   {
      cout << "Enter the score: ";
      cin >> testPtr[i]; // or cin >> *(testPtr + i);
   }
   cout << "Test scores are: " << endl;
   for (int i = 0; i < numTests; i++)
      cout << *(testPtr + i) << endl;

   int *intPtr = new int;

   delete [] testPtr;
   delete intPtr;

   intPtr = nullptr;

   return 0;
}
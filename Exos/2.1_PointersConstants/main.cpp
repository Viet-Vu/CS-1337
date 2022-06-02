#include <iostream>

using namespace std;

/*
1) Ptr to constant data:
 The compiler won't allow the function to modify the "pointed at" data, but the ptr itself can be modified.
 If original data is declared constant (rate array in this Exo) we must have constant data.
 If original data is not declared constant (rate2 array in this Exo) it's good practice to use ptr to const
   if the function is not supposed to modify rate2.

2) Constant ptr:
 Constant ptr contains an address that cannot be modified, but data can be modified.
 MUST initialize the ptr at definition.

 3) Constant ptr to constant data:
 Both the ptr and the data cannot be modified.
 MUST initialize the ptr at definition.

 Principle of least privilege: Give a function the minimum rights to do its job, but no more.
*/

void printArray(const double *dbPtr, int size);
void printArray2(double *dbPtr, int size);
void setToPI(double *const dbPtr, int size);

const double PI = 3.1416;

int main()
{
   const int SIZE = 4;
   const double rate[SIZE] = {20,25,30,35};
   double rate2[SIZE] = {100, 200, 300, 400};

   printArray(rate, SIZE);
   cout << endl;
   printArray2(rate2, SIZE);

   double val = 100;
   double *dbPtr = &val;

   setToPI(dbPtr, 1);
   cout << endl << "val = " << val << endl;

   setToPI(rate2, SIZE);
   printArray(rate2, SIZE);

   return 0;
}

void printArray(const double *dbPtr, int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << *dbPtr << endl;
      dbPtr++;
   }
}

void printArray2(double *dbPtr, int size)
{
   for (int i = 0; i < size; i++)
      cout << *(dbPtr + i) << endl;
}

void setToPI(double *const dbPtr, int size)
{
   for (int i = 0; i < size; i++)
      *(dbPtr + i) = PI;
}
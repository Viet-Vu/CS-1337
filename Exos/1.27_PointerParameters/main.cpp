#include <iostream>

using namespace std;

void swapByPtr(double *doubPtr, double *doubPtr2);
void swapByRef(double &doub1, double &doub2);

int main()
{
   double d1 = 10.5, d2 = 5.6;

   cout << "d1 = " << d1 << ", d2 = " << d2 << endl;

   swapByRef(d1, d2);
   cout << "d1 = " << d1 << ", d2 = " << d2 << endl;

   swapByPtr(&d1, &d2);
   cout << "d1 = " << d1 << ", d2 = " << d2 << endl;

   return 0;
}

void swapByPtr(double *doubPtr, double *doubPtr2)
{
   double temp = *doubPtr;
   *doubPtr = *doubPtr2;
   *doubPtr2 = temp;
}

void swapByRef(double &doub1, double &doub2)
{
   double temp = doub1;
   doub1 = doub2;
   doub2 = temp;
}
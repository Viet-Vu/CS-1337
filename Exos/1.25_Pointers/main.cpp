#include <iostream>

using namespace std;

int main()
{
   int num = 7;

   int *numPtr;
   numPtr = &num;

   cout << "Value pointed at by numPtr is " << *numPtr << endl;
   cout << "Address of num is " << &num << endl;
   cout << "Content of pointer is " << numPtr << endl;

   numPtr = nullptr;
   cout << "Content of pointer is " << numPtr << endl;

   return 0;
}
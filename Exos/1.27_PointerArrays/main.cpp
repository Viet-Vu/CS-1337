#include <iostream>

using namespace std;

int main()
{
   const int SIZE = 4;
   int arr[SIZE] = {10, 20, 30, 40};

   cout << "Array name is starting address of array" << endl;

   cout << "Value of arr[0] is " << arr[0] << endl;
   cout << "Address of arr is " << arr << endl;
   cout << "Address of arr[0] is " << &arr[0] << endl;

   int *intPtr = arr;
   cout << endl << "Pointers can be used like an array name" << endl;
   cout << "Display array content using intPtr[i] notation" << endl;

   for (int i = 0; i < SIZE; i++)
      cout << intPtr[i] << endl;

   cout << endl << "Array name can be used like a constant pointer" << endl;
   cout << "Display array content using *arr notation" << endl;
   cout << "*arr is " << *arr << endl;

   cout << "Value of intPtr is " << intPtr << endl;
   cout << "Value of (intPtr+1) is " << (intPtr + 1) << endl;
   cout << "Value of (intPtr+2) is " << (intPtr + 2) << endl;
   cout << "Value of (intPtr-1) is " << (intPtr - 1) << endl;

   cout << "One int takes " << sizeof(int) << " bytes" << endl;

   cout << endl << "Use *(intPtr+i) notation to access array elements" << endl;
   intPtr = arr;

   for (int i = 0; i < SIZE; i++)
      cout << *(intPtr + i) << endl;

   cout << endl << "Use *(arr+i) notation to access array elements" << endl;

   for (int i = 0; i < SIZE; i++)
      cout << *(arr + i) << endl;

   return 0;
}
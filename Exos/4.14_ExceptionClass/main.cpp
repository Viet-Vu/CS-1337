/*
 * An exception class can be defined in a class and thrown
 * as an exception by a member function.
 * If the exception class has no member, it is used only
 * to signal an error.
 * If the exception class has members, the members can be
 * used to pass error info to the catch block.
 */

#include <iostream>

using namespace std;

class Rectangle
{
private:
   double width, length;
public:
   class NegativeLength {};
   void setLength(double lengthVal)
   {
      if (lengthVal < 0)
         throw NegativeLength();
      else
         length = lengthVal;
   }
};

int main()
{
   Rectangle r;

   double length;
   cout << "Enter length: ";
   cin >> length;

   try
   {
      r.setLength(length);
      cout << "Length successfully set to " << length << endl;
   }
   catch (Rectangle::NegativeLength)
   {
      cout << "Error, length cannot be negative" << endl;
   }

   return 0;
}
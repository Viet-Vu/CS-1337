/*
 * To recover from errors: Use a boolean variable to track if
 * there was an exception thrown and stay in the recovery loop.
 * There can be multiple exceptions thrown from a try block.
 */

#include <iostream>

using namespace std;

class Rectangle
{
private:
   double width, length;
public:
   class NegativeLength
   {
   private:
      double len;
   public:
      NegativeLength(double lenVal)
      {
         len = lenVal;
      }
      double getLen() const
      {
         return len;
      }
   };
   class NegativeWidth
   {
   private:
      double wid;
   public:
      NegativeWidth(double widVal)
      {
         wid = widVal;
      }
      double getWid() const
      {
         return wid;
      }
   };
   void setLength(double lengthVal)
   {
      if (lengthVal < 0)
         throw NegativeLength(lengthVal);
      else
         length = lengthVal;
   }
   void setWidth(double widthVal)
   {
      if (widthVal < 0)
         throw NegativeWidth(widthVal);
      else
         width = widthVal;
   }
};

int main()
{
   Rectangle r;
   double length, width;
   bool valid = false;

   while (!valid)
   {
      cout << "Enter length: ";
      cin >> length;

      cout << "Enter width: ";
      cin >> width;

      try
      {
         r.setLength(length);
         cout << "Length successfully set to " << length << endl;

         r.setWidth(width);
         cout << "Width successfully set to " << width << endl;

         valid = true;
      }
      catch (Rectangle::NegativeLength lengthError)
      {
         cout << "Error, you inputted " << lengthError.getLen() << ", length cannot be negative" << endl;
      }
      catch (Rectangle::NegativeWidth widthError)
      {
         cout << "Error, you inputted " << widthError.getWid() << ", width cannot be negative" << endl;
      }
   }

   return 0;
}
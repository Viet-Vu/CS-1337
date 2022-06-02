/*
 * Exceptions can be used to handle abnormal conditions in
 * a controlled and flexible way.
 *
 * An exception could be an object or a variable. It's used
 * like a signal.
 *
 * One part of the code is the try block.
 * When the try block is executed, the code that detects the
 * abnormal condition is executed. If there is an abnormal
 * condition, an exception is thrown.
 *
 * Another part of the code catches the exception and handles
 * it (exception handler). It is inside a catch block.
 *
 * The types of the catch block and the type of the exception
 * have to match for the exception to be caught by the catch
 * block.
 *
 * If you throw an exception from outside a try block, the
 * exception will not be caught.
 *
 * If an exception is thrown but not caught, the program
 * terminates.
 */

#include <iostream>

using namespace std;

double divide(double, double);

int main()
{
   double x, y, res;

   cout << "Enter x then y:";
   cin >> x >> y;

   try
   {
      res = divide(x, y);
      cout << "Result of division is " << res << endl;
   }
   catch (string str)
   {
      cout << "ERROR: " << str << endl;
   }

   cout << "Done" << endl;

   return 0;
}

double divide(double num, double denum)
{
   if (denum == 0)
   {
      string exceptionMsg = "Divide by zero";
      throw exceptionMsg;
   }
   else
      return num / denum;
}
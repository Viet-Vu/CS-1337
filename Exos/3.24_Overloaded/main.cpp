/*
 * Operators such as +, - and others can be redefined through
 * overloading when used with objects.
 *
 * Overloaded operator must have the same number of operands as
 * the original operator. Example: overloaded + must have 2 operands.
 *
 * To define and overloaded operator, define the member function
 * whose name starts with "operator", followed by the overloaded
 * symbol. Example: "operator+".
 * Then obj1 + obj2 is the same as obj1.operator+(obj2).
 */

#include <iostream>
#include <cmath>

using namespace std;

class Pt2D
{
private:
   double x, y;
public:
   Pt2D(double xVal, double yVal)
   {
      x = xVal;
      y = yVal;
   }
   double operator-(const Pt2D &rhs)
   {
      return (sqrt((x-rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y)));
   }
};

int main()
{
   Pt2D p1(0, 10), p2(0, 15);
   cout << p1.operator-(p2) << endl;
   cout << p1 - p2 << endl;
   cout << p2.operator-(p1) << endl;
   cout << p2 - p1 << endl;

   return 0;
}
/*
 * To enable multi-assignments with the overloaded =,
 * ex: obj3 = obj2 = obj1;
 * obj3 = obj2.operator=(obj1);
 * the member function, when called by obj2, should return obj2.
 * To do that, use return *this;
 *
 * "this" is a predefined pointer that points to the calling object.
 * "this" is automatically passed as a hidden argument to all non-
 * static member functions --> Available for use.
 * "this" is not available for use in a static member function.
 *
 * Most operators can be overloaded: <, <=, >, ==, ++ (post and pre),
 * -- (post and pre), !=, etc.
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
   bool operator == (const Pt2D &rhs)
   {
      return ((x == rhs.x) && (y == rhs.y));
   }
   bool operator < (const Pt2D &rhs)
   {
      return ((x + y) < (rhs.x + rhs.y));
   }
   bool operator > (const Pt2D &rhs)
   {
      return ((x + y) > (rhs.x + rhs.y));
   }
   Pt2D operator = (const Pt2D &rhs)
   {
      x = rhs.x;
      y = rhs.y;
      return *this;
   }
   bool operator <= (const Pt2D &rhs)
   {
      return (*this == rhs) || (*this < rhs);
   }
   Pt2D operator ++ ()
   {
      ++x;
      ++y;
      return *this;
   }
   Pt2D operator ++ (int) // Dummy variable to indicate postfix
   {
      Pt2D temp = *this; // or Pt2D temp(x, y);
      x++;
      y++;
      return temp;
   }
   void printPt2D() const
   {
      cout << "x = " << x << ", y = " << y << endl;
   }

};

int main()
{
   Pt2D p1(10, 100), p2(20, 200), p3(30, 300);

   cout << "p1:" << endl;
   p1.printPt2D();

   cout << "p2:" << endl;
   p2.printPt2D();

   cout << "p3:" << endl;
   p3.printPt2D();

   p3 = p2 = p1;
   cout << endl <<"p3 after p3 = p2 = p1:" << endl;
   p3.printPt2D();

   if (p1 < p2)
      cout << "(p1 < p2) is true" << endl;
   else
      cout << "(p1 < p2) is false" << endl;

   p2 = ++p1;
   cout << endl << "p1 after p2 = ++p1:" << endl;
   p1.printPt2D();
   cout << "p2:" << endl;
   p2.printPt2D();

   p2 = p1++;
   cout << endl << "p1 after p2 = p1++:" << endl;
   p1.printPt2D();
   cout << "p2:" << endl;
   p2.printPt2D();

   if (p1 <= p2)
      cout << "(p1 <= p2) is true" << endl;
   else
      cout << "(p1 <= p2) is false" << endl;

   return 0;
}
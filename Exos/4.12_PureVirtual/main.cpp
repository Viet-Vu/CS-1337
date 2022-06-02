/*
 * A pure virtual function is a virtual function that must be
 * overridden in the derived class, unless we want the derived
 * class to inherit the pure virtual function.
 *
 * A class which has one or more pure virtual functions is an
 * abstract base class.
 *
 * We are not allowed to create objects from an abstract class.
 *
 * Pure virtual functions may be useful as a placeholder, when
 * the class is too generic to be able to come up with a
 * meaningful function definition.
 */

#include <iostream>

using namespace std;

class Student // Abstract class.
{
protected:
   double avgScore;
public:
   virtual double calcGrade() const = 0;
   void setAvgScore(double avgScoreVal)
   {
      avgScore = avgScoreVal;
   }
};

class UTDStudent:public Student // Abstract derived class
{
private:
   int netID;
};

class UTDUGStudent:public UTDStudent // Non-abstract derived class.
{
public:
   double calcGrade() const
   {
      double grade;
      if (avgScore > 95)
         grade = 4.5;
      else if (avgScore > 90)
         grade = 4.0;
      else if (avgScore > 85)
         grade = 3.5;
      else
         grade = 3.0;
      return grade;
   }
};

int main()
{
   UTDUGStudent utdug1;
   utdug1.setAvgScore(96);
   cout << "Grade of UTD UG Student is " << utdug1.calcGrade() << endl;

   // UTDStudent utd1;

   return 0;
}
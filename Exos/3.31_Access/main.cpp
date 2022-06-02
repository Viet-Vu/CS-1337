/*
 * Access to a member in the derived class depends on the class access
 * specifier and the member access specifier in the base class.
 * Class access specifiers and member access specifiers can be public,
 * private, or protected.
 * When an object of the derived class is created, the constructor of
 * the base class is called, then the constructor of the derived class.
 * When an object of the derived class is destroyed, the destructor of
 * the derived class is called, then the destructor of the base class.
 */

#include <iostream>

using namespace std;

class Person // Base class
{
   string name;
   string address;
protected: // If birthMonth were private, Student would not be able to access it.
   int birthMonth;
public:
   Person(string nameStr, string addressStr)
   {
      name = nameStr;
      address = addressStr;
      cout << "Inside constructor of base" << endl;
   }
   ~Person()
   {
      cout << "Inside destructor of base" << endl;
   }
   string getName() const
   {
      return name;
   }
   void setName(string nameStr)
   {
      name = nameStr;
   }
};

class Student : public Person // Derived class
{
   double GPA;
   string major;
public:
   Student (double GPAVal, string majorStr, string nameStr, string addressStr) :
      Person (nameStr, addressStr)
      {
         GPA = GPAVal;
         major = majorStr;
         cout << "Inside constructor of derived" << endl;
      }
   ~Student()
   {
      cout << endl << "Inside destructor of derived" << endl;
   }
   double getGPA() const
   {
      return GPA;
   }
   void setGPA(double GPAVal)
   {
      GPA = GPAVal;
   }
   int getBirthMonth() const
   {
      return birthMonth;
   }
   void setBirthMonth(int birthMonthVal)
   {
      birthMonth = birthMonthVal;
   }
};

int main()
{
   Student s(3.5, "CS", "Solo", "Galaxy");
   s.setName("R2-D2");
   cout << "Name is " << s.getName() << endl;

   s.setGPA(3.2);
   cout << "GPA is " << s.getGPA() << endl;

   s.setBirthMonth(5);
   cout << "Birth month is " << s.getBirthMonth();

   return 0;
}
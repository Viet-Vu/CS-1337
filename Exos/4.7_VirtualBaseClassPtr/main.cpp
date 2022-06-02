/*
 * Binding is the process which maps a function call to the actual
 * function to be executed.
 * In static binding (or early binding), the binding is done at
 * compile time.
 * Static binding can result in problems in some cases if the
 * function is redefined (example of printObject).
 * To address the problem, we need dynamic binding (or late binding).
 * With dynamic binding, the mapping is done not at compile time,
 * but at run time, when the object type (base or derived) is known.
 *
 * To enable dynamic binding, declare the function "virtual" and pass
 * the object by reference or pass a pointer to the object.
 *
 * Another concept in OOP: Polymorphism ("multiple shapes" in Greek).
 * A function can take multiple shapes (or have multiple versions)
 * depending on the type (base or derived) that calls the function.
 *
 * Once a function is declared virtual, all the versions in the
 * derived classes (child, grandchild, etc.) are automatically
 * virtual. You can omit the "virtual" keyword, but it's a good
 * practice to explicitly declare virtual.
 *
 * A virtual function is overridden, a non-virtual function is
 * redefined.
 *
 * Base class pointer: A pointer to a base class object can hold the
 * address of a derived class object.
 * Through the base class pointer, you can access only the members
 * defined in the base class, even if the pointer points to a
 * derived object.
 * When called from a base class pointer, the correct version will
 * be called if the function is virtual.
 */

#include <iostream>

using namespace std;

class Student
{
private:
   string name;
protected:
   double avgScore;
public:
   Student (string nameStr, double avgScoreVal)
   {
      name = nameStr;
      avgScore = avgScoreVal;
   }
   virtual double calcGPA() const
   {
      double GPA;
      if (avgScore > 95)
         GPA = 4.0;
      else if (avgScore > 90)
         GPA = 3.5;
      else if (avgScore > 85)
         GPA = 3.0;
      else
         GPA = 2.5;
      return GPA;
   }
   string getName() const
   {
      return name;
   }
   double getAvgScore() const
   {
      return avgScore;
   }
};

class UGStudent:public Student
{
public:
   UGStudent(string nameStr, double avgScoreVal):Student(nameStr, avgScoreVal) {}
   virtual double calcGPA() const
   {
      double GPA;
      if (avgScore > 98)
         GPA = 4.4;
      else if (avgScore > 95)
         GPA = 4.0;
      else if (avgScore > 90)
         GPA = 3.5;
      else
         GPA = 3.0;
      return GPA;
   }
};

void printObject(const Student&);

int main()
{
   UGStudent ugs("Obi-Wan", 99);
   Student s("Jabba", 99);

   cout << "GPA of undergrad student is " << ugs.calcGPA() << endl;
   cout << "GPA of student is " << s.calcGPA() << endl;

   printObject(ugs);
   printObject(s);

   Student *sPtr = &ugs;
   cout << "GPA of ugs is " << sPtr->calcGPA() << endl;

   return 0;
}

void printObject(const Student &s)
{
   cout << "Name: " << s.getName() << ", average score = " << s.getAvgScore() << ", GPA = " << s.calcGPA() << endl;
}
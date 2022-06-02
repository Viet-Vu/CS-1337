/*
 * A copy constructor is a constructor that is automatically called when an object
 * is created and initialized with another object:
 * 1) Student s2 = s1;
 * 2) An object is passed by value to a function, function parameter is created
 * and initialized with the argument.
 * Note that if the creation and initialization are not in the same statement, it
 * won't invoke the copy constructor. Example:
 * -Student s2;
 * -s2 = s1;
 *
 * If you don't write a copy constructor, the default one will do member assignment,
 * which may be a problem if a member is a pointer.
 *
 * Copy constructor must have this parameter list: (const className &srcObject)
 *
 * Pass by reference because if we pass by value, the copy constructor will
 * automatically call the copy constructor, which will call the copy constructor
 * again, etc. --> endless loop.
 *
 * const because the copy constructor is not supposed to modify the object we
 * copy from (srcObject)
 */

#include <iostream>
#include <iomanip>

using namespace std;

class Student
{
private:
   string name;
   int numTests;
   double *scoresPtr;
   void initScores(double);
public:
   Student(string, int);
   Student(const Student&);
   ~Student();
   void printStud() const;
   void setScore(double, int);
};

int main()
{
   int numTests;
   double score;

   cout << "Enter the number of tests: ";
   cin >> numTests;

   Student s("Kylo", numTests);

   for (int i = 0; i < numTests; i++)
   {
      cout << "Enter score for test " << (i + 1) << ": ";
      cin >> score;
      s.setScore(score, i);
   }

   s.printStud();
   cout << endl;

   Student s2 = s;
   cout << endl << "s2:" << endl;
   s2.printStud();

   s2.setScore(85,0);
   cout << endl << "s2:" << endl;
   s2.printStud();

   cout << endl << "s:" << endl;
   s.printStud();
   cout << endl;

   return 0;
}

Student::Student(string stuName, int testNum)
{
   cout << "In Student constructor" << endl;
   name = stuName;
   numTests = testNum;
   scoresPtr = new double[numTests];

   initScores(0);
}

Student::~Student()
{
   cout << "In Student destructor" << endl;
   delete[] scoresPtr;
}

void Student::printStud() const
{
   cout << "Student " << name << " took " << numTests << " tests" << endl;

   for (int i = 0; i < numTests; i++)
   {
      cout << setw(8) << scoresPtr[i];
      if ((i + 1) % 5 == 0)
         cout << endl;
   }
}

void Student::setScore(double score, int index)
{
   scoresPtr[index] = score;
}

void Student::initScores(double val)
{
   for (int i = 0; i < numTests; i++)
      scoresPtr[i] = val;
}

Student::Student(const Student &s)
{
   name = s.name;
   numTests = s.numTests;
   scoresPtr = new double[numTests];

   for (int i = 0; i < numTests; i++)
      scoresPtr[i] = s.scoresPtr[i];
}